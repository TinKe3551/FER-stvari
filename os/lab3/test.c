#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <semaphore.h>
#include <time.h>


sem_t* sem_ulazak_kupci0;


int main(void) {

    int ID = shmget(IPC_PRIVATE, sizeof(sem_t), 0600);
    sem_ulazak_kupci0 = (sem_t*) shmat(ID, NULL, 0);
    shmctl (ID, IPC_RMID, NULL);

    sem_init(sem_ulazak_kupci0, 1, 0);
    sem_post(sem_ulazak_kupci0);

    while (1) {

        if (fork() == 0) {
            while(1) {
                sem_wait(sem_ulazak_kupci0);
                printf("jebem ti semafore i procese\n");
                sleep(1);
                return 0;
            }
        }

        sleep(1);

    }

    sem_destroy(sem_ulazak_kupci0);
    shmdt(sem_ulazak_kupci0);

    return 0;
    
}