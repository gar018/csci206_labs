#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
  if (argc != 2){
    printf("Usage: %s <trace file>\n", argv[0]);
    exit(1);
  }

  FILE* f = fopen(argv[1], "r");
  if (f==NULL){
    printf("Could not open file %s!\n", argv[1]);
    perror("fatal error");
    exit(-1);
  }

  int i_bytes = 0;    // I type access
  int s_bytes = 0;    // S and M type access
  int l_bytes = 0;    // L type access

  // TODO read file, parse each line, count bytes.
int MAX_STRING_VALUE = 32;
char *buf = malloc(MAX_STRING_VALUE);

while (fgets(buf,MAX_STRING_VALUE,f) != NULL){
    printf("%s",*buf);
}
free(buf);
  // TODO when done, print the results.
  printf("%d, %d, %d\n", i_bytes, l_bytes, s_bytes);
  return 0;
}
