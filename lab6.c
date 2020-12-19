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
char name_of_person[50];
char location[50];
int duration;
daytime time;
struct appointment *next;
} appointment;
void print_appointment(appointment*);
void add_appointment(appointment*, int);
int main()
{
struct appointment *head = (appointment*)malloc(sizeof(appointment));
int count = 0;
int run = 0;
while(run == 0)
{
printf("What command do you want to do? 0. Print 1. Add 2. Time 3. Delete the next appointment 4. Quit\n");
int h;
scanf("%d", &h);
switch(h)
{
case 0:
print_appointment(head);
break;
case 1:
add_appointment(head, count);
if(count == 0)
head = head->next;
count++;
break;
case 2:
break;
case 3:
head = head->next;
count--;
break;
case 4:
run = 1;
break;

}
}
free(head);
return 0;
}
void print_appointment(appointment *a)
{
struct appointment *temp = a;
char monstr[20];
char nameprint[50];
while(temp != NULL)
{
if(strcmp(temp->name_of_person,"")==0){
temp = temp->next;
continue;
}
strcpy(nameprint,temp->name_of_person);
printf("Meet %s", nameprint);
strcpy(nameprint, "");
//nameprint=null;
strcpy(nameprint,temp->location);
printf(" at %s", nameprint);
strcpy(nameprint, "");
printf(" for %d minutes on ", temp->duration);
switch(temp->time.month)
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
printf("%s", monstr);
printf(" %d, ", temp->time.day);
printf("%d", temp->time.year);
printf("at %d", temp->time.hour);
printf(":%d", temp->time.minute);
printf(":%f", temp->time.second);
printf("\n");

temp = temp->next;
}
}
int compare_daytime(daytime a, daytime b)
{
if(a.year > b.year)
{
if(a.month > b.month)
{
if(a.day > b.day)
{
if(a.hour > b.hour)
{
if(a.minute > b.minute)
{
if(a.second > b.second)
{
return 1;
}
}
}
}
}
}
else
{
return 0;
}
}
void add_appointment(appointment *a, int b)
{
printf("Name, Location, Duration, Month, Day, Year, Hour, Minute, Second\n");
char nam[50];
char loc[50];
int dur, mon, da, yr, hr, min;
float sec;
scanf("%s", nam);
scanf("%s", loc);
scanf("%d", &dur);
scanf("%d", &mon);
scanf("%d", &da);
scanf("%d", &yr);
scanf("%d", &hr);
scanf("%d", &min);
scanf("%f", &sec);
printf("%s", nam);


struct appointment* hold = NULL;
hold = (struct appointment*)malloc(sizeof(struct appointment));
strcpy(hold->name_of_person, nam);
strcpy(hold->location, loc);
hold->duration = dur;
hold->time.month = mon;
hold->time.day = da;
hold->time.year = yr;
hold->time.hour = hr;
hold->time.minute = min;
hold->time.second = sec;
hold->next=NULL;
printf("Complete transition into structs\n");
appointment* temp;
temp = (appointment*)malloc(sizeof(appointment));
temp = a;
while(temp->next != NULL)
{
temp = temp->next;
}
temp->next=hold;
}