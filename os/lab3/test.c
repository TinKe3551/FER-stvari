#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <semaphore.h>
#include <time.h>
#include <fcntl.h>


#define SEM_NAME "/JEBENISEMAFORKOJIMECIJELIDANJEBEUSUPAKMOGMOZGA"


sem_t* sem_ulazak_kupci0;


int main(void) {

    sem_ulazak_kupci0 = sem_open(SEM_NAME, O_CREAT, 0666, 10);
    sem_close(sem_ulazak_kupci0);
    sem_unlink(SEM_NAME);
    sem_ulazak_kupci0 = sem_open(SEM_NAME, O_CREAT, 0666, 0);

    while (1) {

        if (fork() == 0) {

            sem_t* bla = sem_open(SEM_NAME, 0);

            sem_wait(bla);
            printf("abcde\n");

        }

    }
    
}