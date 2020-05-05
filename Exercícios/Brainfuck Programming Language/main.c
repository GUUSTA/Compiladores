#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "brainfuck.h"

int main(void) {
    printf("Instancia %d\n", 1);
    interp("+[>,]<-[+.<-]","marrocos");
    printf("\n");
    return 0;
}