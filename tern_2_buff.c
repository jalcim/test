#include <stdio.h>
#include <unistd.h>

int main()
{
  int cpt1, cpt2;
  unsigned char buffer[2][10];

  cpt2 = cpt1 = 0;
  while(cpt2 < 2)
    {
      printf("cpt2 = %d, cpt1 = %d\n", cpt2, cpt1);
      buffer[cpt2][cpt1] = (cpt2 == 0 ? 'a' : 'b');
      (++cpt1) > 9 ? (cpt2++, cpt1 = 0) : 0;
    }
  write(1, buffer[0], 10);
  write(1, "\n", 1);
  write(1, buffer[1], 10);
  write(1, "\n", 1);
}
