#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
  char url[50];
  struct node* next;
}node;
void delete_url(node* node1)
{
    node* temp = (node*) malloc(sizeof(node));
    *temp = *node1;
    while(temp->next != NULL)
    {
        node* temp2 = temp->next;
        if(temp2->next == NULL)
        {
            temp->next = NULL;
            break;
        }
        temp = temp->next;
    }
}

void free_everything(node* node1)
{
    if(node1->next == NULL)
    {
        free(node1);
    }
    else
    {
        free_everything(node1->next);
        free(node1);
    }
}
