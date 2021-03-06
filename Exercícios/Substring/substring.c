#include <string.h>
#include <stdio.h>
#include "substring.h"

void substringBF(char *sub, char *text) {
    int m = strlen(sub);
    int n = strlen(text);
    int i, j;
    int count = 0;
   for (j = 0; j <= n - m; ++j) {
      for (i = 0; i < m && sub[i] == text[i + j]; ++i);
      if (i >= m)
        count++;
   }
   printf("%i\n", count);
}