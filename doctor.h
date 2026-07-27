#ifndef DOCTOR_H
#define DOCTOR_H

#define MAX 100

struct Doctor
{
    int doctorID;
    char name[50];
    char specialization[50];
};

extern struct Doctor doctors[MAX];
extern int doctorCount;

void addDoctor();
void viewDoctors();
void searchDoctor();
void deleteDoctor();

#endif