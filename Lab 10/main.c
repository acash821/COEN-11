#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "appointment.h"

int main() {
    Node *head = NULL;

    while(1)
    {
char command;
        printf("\nChoose a command:\na - Add an appointment\np - Print all of your appointments\nn - Go to your next appointment\ns - Search for an appointment by date\nd - Delete an appointment by date\nw - Write to file\nr-read a file\nq - Quit\n");
scanf("%c", &command);
switch(command)
{
        case 'a':
            head = add(head);
            break;
        case 'p':
            printAll(head);
            break;
        case 'n':
            head = next(head);
            break;
        case 's':
            search(head);
            break;
        case 'd':
            head = delete(head);
            break;
        case 'q':
            head = deleteAll(head);
            return 0;
        case 'w':
            write_to_file(head);
            break;
        case 'r':
            read_file();
            break;
        default:
        printf("Invalid command. Try again.\n\n");
        break;
    }
}
}
