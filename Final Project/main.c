#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "driver.h"
#include "test.h"
#include "history.h"

int main(int argc, char* argv[])
{
    node* head = (node*) malloc(sizeof(node));
    strcpy(head->url, "");
    head->next = NULL;
    char* decision = argv[1];
    int count = 0;
    if(*decision == 'p')
    {
        read_file(head, argv[2]);
    }
    else
    {

        int i = 0;
        while(i == 0)
        {
            int choice;
            printf("Enter your choices 1. Visit a new website 2. Print out the user history 3. Write to file 4. Go back in history 5. Quit");
            scanf("%d", &choice);
            if(choice == 1)
            {
                if(count > 4)
                {
                    head = head->next;
                    add_url(head);
                }
                else
                {
                    add_url(head);
                    count++;
                    printf("%d\n", count);
                }
            }
            else if(choice == 2)
            {
                print_url(head);
            }
            else if(choice == 3)
            {
                write_file(head);
            }
            else if(choice == 4)
            {
                delete_url(head);
                count--;
            }
            else
            {
                i = 1;
            }
        }
    }
    free_everything(head);
}
