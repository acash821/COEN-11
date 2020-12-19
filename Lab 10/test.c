#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "appointment.h"

void write_to_file(Node* head)
{
    FILE* fptr = fopen("book.bin", "wb");
    Node* temp = (Node*) malloc(sizeof(Node));
    temp = head;
    while(temp != NULL)
    {
        fwrite(temp, sizeof(Node), 1, fptr);
        temp = temp->next;
    }
    fclose(fptr);
}

void read_file()
{
    FILE* fptr = fopen("book.bin", "rb");
    Node* temp = (Node*) malloc(sizeof(Node));
    while(fread(temp, sizeof(Node), 1, fptr)== 1)
    {
        printf("Your next appointment is: ");
        print(&(temp->appt));
    }
    fclose(fptr);
}
