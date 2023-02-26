/*
 * A Linux file examiner
 * CSCI206
 * <Your Name>
 */
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {

	if (argc != 2) {
		fprintf(stderr, "Usage: %s FILE\n", argv[0]);
		return 1;
	}

	int f = open(argv[1], O_RDONLY);

	if (f < 0){
		perror("error");
		return 2;
	}

	// use fstat to examine file status

	close (f);
	return 0;
}