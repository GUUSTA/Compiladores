#include "brainfuck.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void te_interp(const char *instrutions, const char *word) {
    
    char environment[999];
    int p_index;
    int word_index;
    
    for (int i = 0; i < strlen(instrutions); i++) {
        char current_instrution = instrutions[i];
        switch (current_instrution) {
        case '>': //Incrementa o ponteiro
            p_index++;
            break;
        case '<': //Decrementa o ponteiro
            p_index--;
            break;
        case '+': //Incrementa o byte na posição indicada pelo ponteiro
            environment[p_index]++;
            break;
        case '-': //Decrementa o byte na posição indicada pelo ponteiro
            environment[p_index]--;
            break;
        case '.': //Imprime byte atual
            printf("%c", environment[p_index]);
            break;
        case ',': //Armazena byte atual
            if (word_index >= strlen(word))
                environment[p_index] = 0;
            else {
                environment[p_index] = word[word_index];
                word_index++;
            }
            break;
        case '#': //Imprime os 10 primeiros armazenados
            for (int i = 0; i < 10; i++)
                printf("%c", environment[i]);
            break;
        }
    }
}
