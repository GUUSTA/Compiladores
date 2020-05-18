#include <string.h>
#include <stdio.h>
#include "substring.h"

void substringBF(char *x, char *y) {
    int m = strlen(x);
    int n = strlen(y);
    int i, j;
    int count = 0;
   /* Searching */
   for (j = 0; j <= n - m; ++j) {
      for (i = 0; i < m && x[i] == y[i + j]; ++i);
      if (i >= m)
        count++;
   }
   printf("%i", count);
}