#ifndef PATIENT_H
#define PATIENT_H

#define MAX 100

struct Patient
{
    int patientID;
    char name[50];
    int age;
    char disease[100];
};

extern struct Patient patients[MAX];
extern int patientCount;

void addPatient();
void viewPatients();
void searchPatient();
void deletePatient();

#endif