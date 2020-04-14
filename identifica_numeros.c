#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 15

int returnIntegerValue(char c);
void cleanText();
bool isAExpectedWord();
void imprime();

char aux[] = "";
char name[] = "ABC45@ 2.7 -7 .3 ";
char result[10][10] = {};
int pos = 1;
int size = 0;

int posResult = 1;
int sizeResult = 0;

int main()
{

    // printf("Enter name: ");
    // scanf("%s", name);
    for (int i = 0; name[i] != '\0'; i++)
    {
        int asciiNumber = returnIntegerValue(name[i]);
        //printf("asciiNumber %d - %c\n", asciiNumber, name[i]);
        if ((asciiNumber >= 48 && asciiNumber <= 57) || asciiNumber == 46 || asciiNumber == 45)
        {
            for (int j = size; j >= pos; j--)
                aux[j] = aux[j - 1];
            aux[pos - 1] = name[i];
            pos++;
            size++;
        }
        else
        {
            if (isAExpectedWord())
            {
                for (int j = sizeResult; j >= pos; j--)
                    aux[j] = aux[j - 1];
                strcpy(result[posResult - 1], aux);
                posResult++;
                sizeResult++;
            }
            cleanText();
        }
    }

    imprime();

    return 0;
}

void imprime()
{
    //printf("%d", sizeResult);
    for (int i = 0; i < posResult; i++)
    {
        printf("%s ", result[i]);
    }
}

bool isAExpectedWord()
{

    int dotCount = 0;
    char lastChar = '\0';
    int index = -1;

    for (int i = 0; i < size; i++)
    {
        if (aux[i] == '.')
        {
            dotCount++;
            if (lastChar == '\0' || lastChar == '-')
            {
                index = i;
                
            }
        }
        lastChar = aux[i];
    }

    if(index != -1) {
        for (int c = size - 1; c >= index - 1; c--)
            aux[c+1] = aux[c];
        aux[index-1] = '0';
    }

    // if(index != -1) {
    //     for (int j = sizeResult; j >= pos; j--)
    //                 aux[j] = aux[j - 1];
    //             strcpy(result[posResult - 1], aux);
    //             posResult++;
    //             sizeResult++;
    // }

    return ((dotCount < 2) && (strcmp(aux, "") != 0));
}

int returnIntegerValue(char c)
{
    return (int)c;
}

void cleanText()
{
    for (int i = 0; i < size; i++)
    {
        aux[i] = 0;
    }
    pos = 1;
    size = 0;
}
