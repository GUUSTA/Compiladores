#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include "compilador.h"

char exprs[2][3];
int count = 0;

bool interp(char input[10]) {
    char var[999];
    char expr[3];
    strcpy(var, "");
    strcpy(expr, "");

    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == ' ' || input[i] == ':' || input[i] == '=' || input[i] == '+') {
        } else {
            char aux[2];
            aux[0]= input[i];
            aux[1]='\0';
            strcat(var, aux); 
       }
    }

    for (int j = 0; j <= strlen(var); j++) {
        if (j == strlen(var)) {
            expr[j] = '\0';
        } else {
            expr[j] = var[j];
        } 
        //printf("pegou: %c\n", expr[j]);
    }

    return verificaExpr(expr);
}

bool verificaExpr(char expr[3]) {
    printf("%s\n", expr);
    int indexOfSameVar = count;
    for (int j = 1; j < strlen(expr); j++) {
        if(isalpha(expr[j])) {
            if (!hasSameVar(expr[j], &indexOfSameVar)) {
                printf("Compilation Error 1\n");
                return false;
            }
        }
    }

    if (isalpha(expr[0])) {
        for (int j = 0; j < strlen(expr); j++) {
            exprs[indexOfSameVar][j] = expr[j];
        }

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                printf("%d %d = %c\n", i, j, exprs[i][j]);
            }
            printf("\n");
        }
        count++;
        return true;
    } else {
       printf("Compilation Error 2\n");
        return false;
    }
}


bool hasSameVar(char var, int *index) {
    for (int j = 0; j < 2; j++) {
        if(var == exprs[j][0]) {
            index = &j;
            return true;
        }
    }
    return false;
}