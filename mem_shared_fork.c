#include <sys/mman.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

unsigned char *buffer;

int fct()
{
  write(1, buffer, 10);
  strncpy(buffer, "prouttttt\n", 10);
  return 0;
}

int main()
{
  buffer = mmap(NULL, 4096, PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
  if (buffer == (unsigned char *)-1)
    perror("mmap");

  strncpy(buffer, "123456789\n", 10);
  if (!fork())
    return fct();
  sleep(2);
  write(1, buffer, 10);
  munmap(buffer, 10);
}
