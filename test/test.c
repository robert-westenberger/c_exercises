#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "helpers.h"

void read_words(FILE *f)
{
  char x[1024];
  /* assumes no word exceeds length of 1023 */
  while (fscanf(f, " %1023s", x) == 1) {
    puts(x);
  }
}

int main()
{
  FILE *fp;
  fp = fopen("./data/big.txt", "r"); //read only
  read_words(fp);
  return 0;
}