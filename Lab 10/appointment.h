#ifndef APPOINTMENT_H
typedef struct DateTime {
    int month;
    int day;
    int year;
    int hour;
    int minute;
    float second;
} DateTime;

typedef struct Appointment {
    char name[50];
    char location[50];
    int duration;
    DateTime date_time;
} Appointment;

typedef struct Node {
    Appointment appt;
    struct Node *next;
} Node;
#define APPOINTMENT_H



#endif // APPOINTMENT_H
