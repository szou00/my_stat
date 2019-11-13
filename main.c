#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

int main() {

  struct stat *buf;
  buf = malloc(sizeof(struct stat));
  stat("main.c", buf);

  //file size
  int size = buf->st_size;
  printf("\nFile size: %d\n",size);

  //mode (permissions)
  int permissions = buf->st_mode;
  printf("File permissions: %d\n",permissions);

  //time of last access (displayed in the following format: Fri Oct 28 09:03:01 2016  //
  long *time = &buf->st_atime;
  char *access = ctime(time);
  printf("Last accessed: %s\n",access);
}
