#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "appointment.h"

int validate(Appointment *appt) {
    if(strcmp(appt->name, "") == 0) {
        printf("Name cannot be empty.\n");
        return 0;
    } else if(appt->duration < 0) {
        printf("Duration must be at least 0.\n");
        return 0;
    } else if(appt->date_time.month < 1 || appt->date_time.month > 12) {
        printf("Month must be between 1 and 12.\n");
        return 0;
    } else if(appt->date_time.month == 2) {
        if(appt->date_time.day < 1 || appt->date_time.day > 28) {
            printf("Day must be between 1 and 28.\n");
            return 0;
        } else {
            return 1;
        }
    } else if(appt->date_time.month == 4 || appt->date_time.month == 6 ||
        appt->date_time.month == 9 || appt->date_time.month == 11) {
        if(appt->date_time.day < 1 || appt->date_time.day > 30) {
            printf("Day must be between 1 and 30.\n");
            return 0;
        } else {
            return 1;
        }
    } else if(appt->date_time.month == 1 || appt->date_time.month == 3 ||
        appt->date_time.month == 5 || appt->date_time.month == 7 ||
        appt->date_time.month == 8 || appt->date_time.month == 10 ||
        appt->date_time.month == 12) {
        if(appt->date_time.day < 1 || appt->date_time.day > 31) {
            printf("Day must be between 1 and 31.\n");
            return 0;
        } else {
            return 1;
        }
    } else if(appt->date_time.year < 2020) {
        printf("Year not valid.\n");
        return 0;
    } else if(appt->date_time.hour < 0 || appt->date_time.hour > 23) {
        printf("Hour must be between 0 and 23.\n");
        return 0;
    } else if(appt->date_time.minute < 0 || appt->date_time.minute > 59) {
        printf("Hour must be between 0 and 59.\n");
        return 0;
    } else if(appt->date_time.second < 0 || appt->date_time.second > 59.999999) {
        printf("Hour must be between 0 and 59.999999.\n");
        return 0;
    } else {
        return 1;
    }
}

int compDate(DateTime *left, DateTime *right) {
    if(left->year < right->year) {
        return -1;
    } else if (left->year == right->year) {
        if(left->month < right->month) {
            return -1;
        } else if(left->month == right->month) {
            if(left->day < right->day) {
                return -1;
            } else if(left->day == right->day) {
                if(left->hour < right->hour) {
                    return -1;
                } else if(left->hour == right->hour) {
                    if(left->minute < right->minute) {
                        return -1;
                    } else if(left->minute == right->minute) {
                        if(left->second < right->second) {
                            return -1;
                        } else if(left->second == right->second) {
                            return 0;
                        } else {
                            return 1;
                        }
                    } else {
                        return 1;
                    }
                } else {
                    return 1;
                }
            } else {
                return 1;
            }
        } else {
            return 1;
        }
    } else {
        return 1;
    }
}

Node *create(Appointment appt, Node *next) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if(new_node == NULL)
    {
        printf("Error creating a new node.\n");
        exit(0);
    }
    new_node->appt = appt;
    new_node->next = next;

    return new_node;
}

Node *add(Node *head) {
    Appointment appt;
    printf("Who is your appointment with?\n");
    scanf("%s", appt.name);
    printf("Where is your appointment?\n");
    scanf("%s", appt.location);
    printf("How long (in minutes) is your appointment?\n");
    scanf("%d", &appt.duration);
    printf("What day and time is your appointment? Format: MM/DD/YYYY HH:MM:SS.SS\n");
    scanf("%d/%d/%d %d:%d:%f", &appt.date_time.month, &appt.date_time.day, &appt.date_time.year, &appt.date_time.hour, &appt.date_time.minute, &appt.date_time.second);
    if(validate(&appt) == 0)
    {
        printf("Please try again.\n");
        return head;
    }

    if(head == NULL)
    {
        Node* new_node =  create(appt, NULL);
        head = new_node;
        return head;
    }
    else
    {
        Node *cursor = head;
        Node *prev = NULL;
        while(cursor != NULL)
        {
            if(compDate(&(appt.date_time), &(cursor->appt.date_time)) <= 0)
            {
                if(cursor == head)
                {
                    Node* new_node = create(appt, head);
                    head = new_node;
                    return head;
                }
                else
                {
                    Node* new_node = create(appt, cursor);
                    prev->next = new_node;
                    return head;
                }
            }

            prev = cursor;
            cursor = cursor->next;
        }
        Node* new_node =  create(appt, NULL);
        prev->next = new_node;
        return head;
    }

    return head;
}

void printDateTime(DateTime *date_time) {
    char month[10];
    int hour;
    char ampm[3];

    switch(date_time->month) {
        case 1:
            strcpy(month, "January");
            break;
        case 2:
            strcpy(month, "February");
            break;
        case 3:
            strcpy(month, "March");
            break;
        case 4:
            strcpy(month, "April");
            break;
        case 5:
            strcpy(month, "May");
            break;
        case 6:
            strcpy(month, "June");
            break;
        case 7:
            strcpy(month, "July");
            break;
        case 8:
            strcpy(month, "August");
            break;
        case 9:
            strcpy(month, "September");
            break;
        case 10:
            strcpy(month, "October");
            break;
        case 11:
            strcpy(month, "November");
            break;
        case 12:
            strcpy(month, "December");
            break;
        default:
            break;
    }

    if(date_time->hour > 12) {
        hour = date_time->hour - 12;
        strcpy(ampm, "PM");
    } else {
        if(date_time->hour == 0) {
            hour = 12;
        } else {
            hour = date_time->hour;
        }

        if(date_time->hour == 12) {
            strcpy(ampm, "PM");
        } else {
            strcpy(ampm, "AM");
        }
    }

    printf("%s %d %d %d:%d:%f %s", month, date_time->day, date_time->year, hour, date_time->minute, date_time->second, ampm);
}

DateTime findEnd(DateTime *start, int duration) {
    DateTime end = *start;
    end.minute += duration;

    if(end.minute > 59) {
        end.hour += end.minute / 60;
        end.minute = end.minute % 60;
    }
    if(end.hour > 23) {
        end.day += end.hour / 24;
        end.hour = end.hour % 24;
    }
    if(end.day > 31) {
        end.month += end.day / 32;
        end.day = end.day % 32;
    }
    if(end.month > 12) {
        end.year += end.month / 13;
        end.month = end.month % 13;
    }

    return end;
}

void print(Appointment *next) {
    DateTime end = findEnd(&(next->date_time), next->duration);
    printf("Meet %s at %s for %d minutes starting at ", next->name, next->location, next->duration);
    printDateTime(&(next->date_time));
    printf(" until ");
    printDateTime(&(end));
    printf("\n");
}

void printAll(Node *head) {
    if(head == NULL) {
        printf("You have no upcoming appointments.\n");
        return;
    }

    Node *cursor = head;
    while(cursor != NULL) {
        print(&(cursor->appt));
        cursor = cursor->next;
    }

    return;
}

Node *next(Node *head) {
    if(head == NULL) {
        printf("You have no upcoming appointments.\n");
        return NULL;
    }

    printf("Your next appointment is: ");
    print(&(head->appt));
    Node *front = head;
    head = head->next;
    front->next = NULL;
    if(front == head) {
        head = NULL;
    }

    free(front);
    return head;
}

void search(Node *head) {
    DateTime findDate;
    printf("What time is the appointment you're looking for? Format: MM/DD/YYYY HH:MM:SS.SS\n");
    scanf("%d/%d/%d %d:%d:%f", &findDate.month, &findDate.day, &findDate.year, &findDate.hour, &findDate.minute, &findDate.second);

    Node *cursor = head;
    while(cursor != NULL) {
        if(compDate(&(cursor->appt.date_time), &(findDate)) == 0) {
            print(&(cursor->appt));
        }
        cursor = cursor->next;
    }

    return;
}

Node *delete(Node *head) {
    DateTime findDate;
    printf("What time is the appointment you're looking for? Format: MM/DD/YYYY HH:MM:SS.SS\n");
    scanf("%d/%d/%d %d:%d:%f", &findDate.month, &findDate.day, &findDate.year, &findDate.hour, &findDate.minute, &findDate.second);

    Node *cursor = head;
    Node *prev = NULL;
    while(cursor != NULL) {
        if(compDate(&(cursor->appt.date_time), &(findDate)) == 0) {
            Node *temp = cursor;
            printf("Deleting: ");
            print(&(cursor->appt));
            if(cursor == head) {
                head = cursor->next;
            } else if(cursor->next == NULL) {
                prev->next = NULL;
            } else {
                prev->next = cursor->next;
            }
            free(temp);
        }
        prev = cursor;
        cursor = cursor->next;
    }

    return head;
}

Node *deleteAll(Node *head) {
    while(head != NULL) {
        Node *temp = head;
        head = head->next;
        free(temp);
    }

    return NULL;
}
