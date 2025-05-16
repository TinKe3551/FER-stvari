#include <stdio.h>
#include <unistd.h>


int main(void) {

    printf("prodavac je na pauzi\n");

    int lol = 1;

    while (lol > 0) {

        // printf("glavni proces %d", getpid());

        lol = fork();

    }

    printf("kupac %d krepava od gladi \n", getpid());

    return 0;

}