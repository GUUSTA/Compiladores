#include <stdio.h>
#include <stdlib.h>
#include "ParserLinkedList.h"

typedef enum TokenType {
    TEXT=1,
    INTEGER=2,
    REAL=3,
} TokenType;

typedef union Value {
    int i;
    double r;
    char *t;
} Value;

typedef struct tList {
    TokenType tt;
    Value value;
    struct tList *prox;
} *List;

List add(Value value, TokenType type) {
    
    List newList = (struct tList*) malloc(sizeof(struct tList));

    switch (type)
    {
    case TEXT:
        newList->value.t = value.t;
        break;
    case INTEGER:
         newList->value.i = value.i;
        break;
    case REAL:
        newList->value.r = value.r;
        break;
    default:
        break;
    }
    newList->tt = type;
    return newList;
}

int main(int argc, char *argv[]) {
    Value value;
    List list =  NULL;

    value.t = "Ola, tudo bem?";
    list = add(value, TEXT);
    value.i = 81;
    list->prox = add(value, INTEGER);
    value.r = 2048.2048;
    list->prox->prox = add(value, REAL);

    printf("TEXT: %s\n", list->value.t);
    printf("INTEGER: %d\n", list->prox->value.i);
    printf("REAL: %f\n", list->prox->prox->value.r);

    return 0;
}