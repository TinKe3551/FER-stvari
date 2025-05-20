#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <semaphore.h>
#include <time.h>
#include <fcntl.h>


#define SEM_NAME "/JEBENISEMAFORKOJIMECIJELIDANJEBEUSUPAKMOGMOZGA"


sem_t* sem;


int main(void) {

    sem = sem_open(SEM_NAME, O_CREAT, 0666, 30);
    sem_close(sem);
    sem_unlink(SEM_NAME);

    while (1) {

        if (fork() == 0) {

            sem = sem_open(SEM_NAME, O_CREAT, 0666, 3);

            sem_wait(sem);
            printf("abcde\n");

        }

    }
    
}