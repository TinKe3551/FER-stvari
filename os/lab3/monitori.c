#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <time.h>
#include <fcntl.h>
#include <pthread.h>


pthread_mutex_t monitor;
pthread_mutex_t br_st_mon;

pthread_cond_t red_uvj_pb;
pthread_cond_t red_uvj_st;

int studenata_u_sobi = 0;
int partibrejker_u_sobi = 0;
int zadnji_broj_studenta;


void randusleep(int l, int h) {
    srand(time(NULL) + clock());
    int t = rand() % (h - l);
    t += l;
    // printf("%d\n", t);
    usleep(t);
}


void* dr_student(void* a) {

    pthread_mutex_lock(&br_st_mon);
    int broj_studenta = ++zadnji_broj_studenta;
    pthread_mutex_unlock(&br_st_mon);

    randusleep(100000, 500000);

    for (int i = 0; i < 3; i++) {

        // ulazak u sobu
        pthread_mutex_lock(&monitor);

        while (partibrejker_u_sobi) {
            pthread_cond_wait(&red_uvj_st, &monitor);
        }

        studenata_u_sobi++;

        pthread_mutex_unlock(&monitor);
        pthread_cond_signal(&red_uvj_pb);

        // boravak u sobi
        printf("student %d je u sobi\n", broj_studenta);
        randusleep(1000000, 2000000);

        // izlazak iz sobe
        pthread_mutex_lock(&monitor);

        studenata_u_sobi--;

        pthread_mutex_unlock(&monitor);
        pthread_cond_signal(&red_uvj_pb);

        printf("student %d izlazi iz sobe\n", broj_studenta);

        randusleep(1000000, 2000000);
    
    }

    printf("student %d ide doma\n", broj_studenta);

    return 0;

}


void* dr_partibrejker(void* a) {

    while (1) {

        randusleep(100000, 1000000);

        pthread_mutex_lock(&monitor);

        if (studenata_u_sobi < 3) {
            pthread_mutex_unlock(&monitor);
            pthread_cond_broadcast(&red_uvj_st);
            continue;
        }

        partibrejker_u_sobi = 1;
        printf("partibrejker je u sobi\n");
        
        pthread_mutex_unlock(&monitor);
        pthread_cond_broadcast(&red_uvj_st);

        pthread_mutex_lock(&monitor);

        while (studenata_u_sobi > 0) {
            pthread_cond_wait(&red_uvj_pb, &monitor);
        }

        partibrejker_u_sobi = 0;

        pthread_mutex_unlock(&monitor);
        pthread_cond_broadcast(&red_uvj_st);

        printf("partibrejker izlazi iz sobe\n");

    }

    return 0;

}


int main(void) {

    int n = 0;
    while (n < 3) {
        printf("broj studenata (barem 3): ");
        scanf("%d", &n);
    }

    pthread_t partibrejker;
    pthread_t studenti[n];

    pthread_create(&partibrejker, NULL, dr_partibrejker, NULL);
    

    for (int i = 0; i < n; i++) {
        pthread_create(&studenti[i], NULL, dr_student, NULL);
    }

    for (int i = 0; i < n; i++) {
        pthread_join(studenti[i], NULL);
    }

    return 0;

}