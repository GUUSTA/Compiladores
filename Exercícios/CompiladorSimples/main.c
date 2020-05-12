#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "compilador.h"

int main(void) {
    // int i;
    // for(i = 0; i < 7; i ++) {
    //     if (i == 6) {
    //         printf("OK\n");
    //     } else {
    //         char input[10];
    //         strcpy(input, "");
    //         scanf("%s", input);
    //         printf("%s\n", input);
    //         if(interp(input)) {
    //             continue;
    //         } else {
    //             printf("Compilation Error\n");
    //             break;
    //         }
    //     }
    // }

    bool aceita = true;

    //EXEMPLO 1
    // aceita = interp("a := 0");
    // aceita = interp("b := 1");
    // aceita = interp("c := a + b");
    // aceita = interp("d := a + b");

    //EXEMPLO 2
    aceita = interp("a := 0");
    aceita = interp("b := 1");
    aceita = interp("c := a + b");
    aceita = interp("d := a + b");
    aceita = interp("e := a + c");
    aceita = interp("f := a + c");
    if(aceita) {
        printf("OK\n");
    } else {
        printf("Compilation Error\n");
    }
    
    return 0;
}

// a := 0
// b := 1
// c := a + b
// d := a + b

// a := 0
// b := 1
// c := a + b
// d := a + b
// e := a + c
// f := a + c