#include <stdio.h>
#include <unistd.h>

int main(void) {

	while (fork()) {
		printf("%d\n", getpid());
	}

	return 0;

}
