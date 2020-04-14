#include "ParserLinkedList.h"
#include <stdio.h>


int main(int argc, char *argv[]) {
    Value value;
    Value value;
    List l =  NULL;

    value.t = "Ola, tudo bem?";
    l = add(value, TEXT);
    value.i = 81;
    l->prox = add(value, INTEGER);
    value.r = 2048.2048;
    l->prox->prox = add(value, REAL);

    return 0;
}