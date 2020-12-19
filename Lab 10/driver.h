#ifndef DRIVER_H_INCLUDED
#include "appointment.h"
int validate(Appointment *);
int compDate(DateTime *, DateTime *);
Node *create(Appointment, Node *);
Node *add(Node *);
void printDateTime(DateTime *);
DateTime findEnd(DateTime *, int);
void print(Appointment *);
void printAll(Node *);
Node *next(Node *);
void search(Node *);
Node *delete(Node *);
Node *deleteAll(Node *);
#define DRIVER_H_INCLUDED



#endif // DRIVER_H_INCLUDED
