#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <semaphore.h>
#include <time.h>
#include <fcntl.h>


#define SEM_STOL "SEM_STOL"
#define SEM_KUPCI0 "SEM_KUPCI0"
#define SEM_KUPCI1 "SEM_KUPCI1"
#define SEM_KUPCI2 "SEM_KUPCI2"


char* sastojci[] = {
    "kruh",
    "šunka",
    "sir"
};

int* stol;


void proc_trgovac() {

    sem_t* sem_stol = sem_open(SEM_STOL, 0);

    sem_wait(sem_stol);
    printf("trgovac je došao do stola\n");

}


void proc_kupac(int broj_kupca, int vrsta_kupca) {

    sem_t* sem_stol = sem_open(SEM_STOL, 0);

    sem_wait(sem_stol);
    printf("kupac je došao do stola\n");

}


sem_t* stavi_semafor(char* ime) {
    
    // za slučaj da je semafor otprije otvoren bez da je nakon toga zatvoren
    sem_t* sem = sem_open(ime, O_CREAT, 0666, 1234);
    sem_close(sem);
    sem_unlink(ime);

    // ovo je zapravo semafor koji će se koristiti
    sem = sem_open(ime, O_CREAT, 0666, 1000);

    return sem;

}


int main(void) {
    
    sem_t* sem_stol = stavi_semafor(SEM_STOL);
    sem_t* sem_kupci0 = stavi_semafor(SEM_KUPCI0);
    
    int ID = shmget(IPC_PRIVATE, sizeof(int), 0600);
    stol = (int*) shmat(ID, NULL, 0);
    shmctl(ID, IPC_RMID, NULL);
    *stol = -1;

    int f = fork();

    if (f > 0) {
        proc_trgovac();
    }

    else if (f == 0) {

        int broj_kupca = 0;

        for (int i = 0; i < 20; i++) {

            int f2 = fork();

            if (f2 > 0) {

                sleep(1);

                continue;

            }

            else if (f2 == 0) {

                srand(clock());
                int vrsta_kupca = rand() % 3;
                proc_kupac(broj_kupca, vrsta_kupca);

            }

            return 0;

        }

    }

    return 0;

}