#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "history.h"

void read_file(node* node1, char* name)
{
    FILE* ftr;
    ftr = fopen(name, "rb");
    char holding[50];
    node* temp = (node*) malloc(sizeof(node));
    while(fread(holding, sizeof(holding), 1, ftr) == 1)
    {
        printf("\n");
        decrypt(holding);
        printf("%s", holding);
    }
    printf("*");
    free(temp);
    fclose(ftr);
}

void encrypt(char* at)
{
    int a = strlen(at);
    int i = 0;
    while(i < a)
    {
        at[i] = at[i]^5;
        i++;
    }
}

void decrypt(char* at)
{
    int a = strlen(at);
    int i = 0;
    while(i < a)
    {
        at[i] = 5^at[i];
        i++;
    }
}
