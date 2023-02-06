#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int MAXLINES = 100;
int MAXBYTE = 255;
int DEFAULTEXPECTED = 10;

int read_file_lines(FILE * fp, char buffer[MAXLINES][MAXBYTE+1],int lines_expected);

int main(int argc, char * argv[]) {
    FILE *fp;
    int lines_expected = 10;

    if (argc <= 1) {
        printf("%d\n",argc);
        exit(1);
    }
    else if (argc >= 3) {
        lines_expected = atoi(argv[2]);    
    }
    char buffer[MAXLINES][MAXBYTE+1];
    char fileName[strlen(argv[1])];
    strcpy(fileName,argv[1]); 

    fp = fopen(fileName,"r");
    if (fp == NULL) {
        perror("fopen failed");
        exit(1);
    }

    int actual_size = read_file_lines((FILE*)fp,buffer,lines_expected);
    for (int i = 0; i < actual_size; i++) {
        printf("%s",buffer[i]);
    }
    fclose(fp);
    exit(0);
}

int read_file_lines(FILE * fp, char buffer[MAXLINES][MAXBYTE+1],int lines_expected)
{   
    int total_size = 0;
    for (int i = 0; i < lines_expected; i++) {
        fgets(buffer[i],MAXBYTE,(FILE*)fp);
        total_size += sizeof(buffer[i]);
    }
    return total_size/sizeof(buffer[0]);
}
