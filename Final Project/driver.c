#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "history.h"

void add_url(node* node1)
{
    if(node1->next == NULL)
    {
        char holding[50];
        printf("Enter URL: \n");
        scanf("%s", holding);
        if(strcmp(node1->url,"") == 0)
        {
            strcpy(node1->url, holding);
        }
        else
        {
            node* hold = (node*) malloc(sizeof(node));
            strcpy(hold->url, holding);
            node1->next = hold;
        }
    }
    else
    {
        add_url(node1->next);
    }
}
void print_url(node* node1)
{
    if(node1->next != NULL)
    {
        char holding[50];
        strcpy(holding, node1->url);
        printf("%s", holding);
        printf("\n");
        print_url(node1->next);
    }
    else
    {
        char holding[50];
        strcpy(holding, node1->url);
        printf("%s*\n", holding);
    }
}
void write_file(node* node1)
{
    FILE* fpointer;
    char holding[50];
    fpointer = fopen("result.bin", "wb");
    node* temp = (node*) malloc(sizeof(node));
    temp = node1;
    while(temp != NULL)
    {
        strcpy(holding, temp->url);
        encrypt(holding);
        fwrite(holding, sizeof(holding), 1, fpointer);
        temp = temp->next;
    }
    fclose(fpointer);
}
