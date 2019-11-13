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

  //second part of assignment
  //print file size in human readable form
  char buffer[50];
  sprintf(buffer, "File size: %d KB\n", size);
  if (size >= 1024) {
    size = size/ 1024;
    sprintf(buffer, "File size: %d MB\n", size);
  }
  if (size >= 1024) {
    size = size / 1024;
    sprintf(buffer, "File size: %d GB\n", size);
  }
  printf("%s", buffer);

  //print out permissions in ls -l form


}
