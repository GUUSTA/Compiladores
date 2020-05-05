#include "brainfuck.h"
#include <string.h>
#include <stdio.h>

int word_index = 0;
int p_index = 0;
char environment[999];

void interp(char *instrutions, char *word) {

    int brackets_count = 0;
    char brackets_instrutions[999];
    int i, j;
    for (i = 0; i < strlen(instrutions); i++) {
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
        case '[': // Inicia um loop
            brackets_count = 1;
            i++;
            strcpy(brackets_instrutions, ""); //Limpa o código
            do {
                current_instrution = instrutions[i];
                if (current_instrution == '[') { 
                    brackets_count++;
                } else if (current_instrution == ']') { // Termina um loop 
                    brackets_count--;
                }

                if (brackets_count == 0) { //Toda a parte de dentro dos parenteses foi lida
                    break;
                }

                char aux[20];
                aux[0]= current_instrution;
                aux[1]='\0';
                strcat(brackets_instrutions, aux); // Concatena a nova instrucao com as demais
                i++;
            }
            while (1);

            do {
                interp(brackets_instrutions, word);
            }
            while (environment[p_index] != 0);
            break;  
        case '#': //Imprime os 10 primeiros armazenados
            for (j = 0; j < 10; j++) {
                printf("%c", environment[i]);
            }
            break;
        }
    }
}

// int main(void) {
//     printf("Instancia %d\n", 1);
//     interp("+[>,]<-[+.<-]","marrocos");
//     printf("\n");
//     return 0;
// }
