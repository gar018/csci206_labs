/*
 * A Linux file examiner
 * CSCI206
 * Gordon Rose
 */
#include <stdio.h>
#include <stdlib.h>
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
    struct stat * thisFile = malloc(sizeof(struct stat));
    fstat(f,thisFile);
    printf("st_dev: %ld\n",thisFile->st_dev);
    printf("st_ino: %ld\n",thisFile->st_ino);
    printf("st_mode: %o\n",thisFile->st_mode);
    printf("st_nlink: %ld\n",thisFile->st_nlink);
    printf("st_uid: %ud\n",thisFile->st_uid);
    printf("st_gid: %ud\n",thisFile->st_gid);
    printf("st_rdev: %ld\n",thisFile->st_rdev);
    printf("st_size: %ld\n",thisFile->st_size);
    printf("st_blksize: %ld\n",thisFile->st_blksize);
    printf("st_blocks: %ld\n",thisFile->st_blocks);

    //const time_t * atime = &thisFile->st_atime;
    printf("st_atime: %s", ctime(&thisFile->st_atime));
    printf("st_mtime: %s",ctime(&thisFile->st_mtime));
    printf("st_ctime: %s",ctime(&thisFile->st_ctime));
    
    free(thisFile);

	close (f);
	return 0;
}
