#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct car
{
    char make[25];
    char model[25];
    int price;
    struct car* next;
}car;
void add_car(car* node1)
{
    if(node1 == NULL)
    {
        printf("Enter Make of the car: \n");
        scanf("%s", node1->make);
        printf("Enter Model of the car: \n");
        scanf("%s", node1->model);
        printf("Enter Price of the car: \n");
        scanf("%d", &node1->price);
    }
    else if(node1->next == NULL)
    {
        car* hold = (car*) malloc(sizeof(car));
        printf("Enter Make of the car: \n");
        scanf("%s", hold->make);
        printf("Enter Model of the car: \n");
        scanf("%s", hold->model);
        printf("Enter Price of the car: \n");
        scanf("%d", &hold->price);
        node1->next = hold;
    }
    else
    {
        add_car(node1->next);
    }
}
void display_garage(car* node1)
{
    if(node1->next != NULL)
    {
        printf("%s%s for $%d\n", node1->make, node1-> model, node1->price);
        display_garage(node1->next);
    }
    else
    {
        printf("%s%s for $%d\n", node1->make, node1-> model, node1->price);
    }
}
void free_everything(car* node1)
{
    if(node1->next != NULL)
    {
        free_everything(node1->next);
    }
    else
    {
        free(node1);
    }
}
int main()
{
    int i = 0;
    car* garage = (car*) malloc(sizeof(car));
    while(i == 0)
    {
        int choice;
        printf("Enter the choice 1. Add a car to the garage 2. Display all the cars 3. Remove the first car in the garage 4. Quit");
        scanf("%d", &choice);
        if(choice == 1)
        {
            add_car(garage);
        }
        else if(choice == 2)
        {
            display_garage(garage);
        }
        else if(choice == 3)
        {
            garage = garage->next;
        }
        else
        {
            i = 1;
        }
    }
    free_everything(garage);
}