#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <semaphore.h>
#include <time.h>
#include <fcntl.h>


#define SEM_NAME "/JEBENISEMAFORKOJIMECIJELIDANJEBEUSUPAKMOGMOZGA"


sem_t* sem_ulazak_kupci0;


int main(void) {

    sem_ulazak_kupci0 = sem_open(SEM_NAME, O_CREAT, 0666, 30);
    sem_close(sem_ulazak_kupci0);
    sem_unlink(SEM_NAME);

    while (1) {

        if (fork() == 0) {

            sem_ulazak_kupci0 = sem_open(SEM_NAME, O_CREAT, 0666, 3);

            sem_wait(sem_ulazak_kupci0);
            printf("abcde\n");

        }

    }
    
}