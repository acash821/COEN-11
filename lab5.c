#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct daytime
{
    int month;
    int day;
    int year;
    int hour;
    int minute;
    float second;
} daytime;
typedef struct appointment
{
  char name_of_person[10];
  char location[25];
  int duration;
  daytime time;
} appointment;
void add_appointment(appointment*, int);
void print_appointment(appointment);
void print_time(appointment);
struct appointment add_duration(int, appointment);
int main()
{
    int run = 0;
    int count = 0;
    int size = 5;
    appointment* book = (appointment*) malloc(size * sizeof(appointment));
    while(run == 0)
    {
if(count == size)
        {
            size *= 2;
            realloc(book, size * sizeof(appointment));
        }
        printf("What command do you want to do? 0. Print 1. Add  2. Time 3. Delete all data 4. Quit");
        int hold;
        scanf("%d", &hold);
        switch(hold)
        {
            case 0:
                printf("Name\tLocation\tDuration\tMonth\tDay\tYear\tTime\n");
                int i = 0;
                    while(i < count)
                    {
                        print_appointment(*(book+i));
                        i++;
                    }
                    break;
            case 1:
                add_appointment(book, count);
                count++;
                break;
            case 2:
                print_time(*(book));
                break;
            case 3:
                size = 5;
                count = 0;
                realloc(book, size * sizeof(appointment));
                break;
            case 4:
                run = 1;
                break;
           
        }
    }
    free(book);
}
void add_appointment(appointment* a, int counter)
{
    printf("Name, Location, Duration, Month, Day, Year, Hour, Minute, Second\n");
    int temp;
    float temp_2;
    char hold1[25];
    char hold2[25];
    scanf("%s", (a+counter)->name_of_person);
    scanf("%s", (a+counter)->location);
    scanf("%d", &temp);
    if(temp > 0)
    {
        (a+counter)->duration = temp;  
    }
    else
    {
        (a+counter)->duration = 35;
    }
    scanf("%d", &temp);
    if(temp > 0 && temp < 13)
    {
        (a+counter)->time.month = temp;  
    }
    else
    {
        (a+counter)->time.month = temp % 12;
    }
    scanf("%d", &temp);
    if(temp > 0 && temp < 13)
    {
        (a+counter)->time.day = temp;  
    }
    else
    {
        (a+counter)->time.day = temp % 30;
    }
    scanf("%d", &temp);
    if(temp >= 2020)
    {
        (a+counter)->time.year = temp;  
    }
    else
    {
        (a+counter)->time.year = 2021;
    }
    scanf("%d", &temp);
    if(temp > 2019)
    {
        (a+counter)->time.hour = temp;  
    }
    else
    {
        (a+counter)->time.hour = temp % 24;
    }
    scanf("%d", &temp);
    if(temp < 60)
    {
        (a+counter)->time.minute = temp;  
    }
    else
    {
        (a+counter)->time.minute = temp % 60;
    }
    scanf("%f", &temp_2);
    (a+counter)->time.second = temp_2;
}
void print_appointment(appointment a)
{
    char monstr[20];
    switch(a.time.month)
    {
        case 1:
            strcpy(monstr, "January");
            break;
        case 2:
            strcpy(monstr, "February");
            break;
        case 3:
            strcpy(monstr, "March");
            break;
        case 4:
            strcpy(monstr, "April");
            break;
        case 5:
            strcpy(monstr, "May");
            break;
        case 6:
            strcpy(monstr, "June");
            break;
        case 7:
            strcpy(monstr, "July");
            break;
        case 8:
            strcpy(monstr, "August");
            break;
        case 9:
            strcpy(monstr, "September");
            break;
        case 10:
            strcpy(monstr, "October");
            break;
        case 11:
            strcpy(monstr, "November");
            break;
        case 12:
            strcpy(monstr, "December");
            break;
    }
    printf("Meet %s", a.name_of_person);
    printf(" at %s", a.location);
    printf(" for %d minutes on ", a.duration);
    printf("%s", monstr);
    printf(" %d, ", a.time.day);
    printf("%d", a.time.year);
    printf("at %d", a.time.hour);
    printf(":%d", a.time.minute);
    printf(":%f", a.time.second);
    printf("\n");
}
void print_time(appointment a)
{
    printf(" on %d/", a.time.month);
    printf("%d/", a.time.day);
    printf("%d/", a.time.year);
    printf("at %d", a.time.hour);
    printf(":%d", a.time.minute);
    printf(":%f", a.time.second);
}