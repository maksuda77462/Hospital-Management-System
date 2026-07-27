#include <stdio.h>
#include <string.h>
#include "patient.h"

struct Patient patients[MAX];
int patientCount = 0;

// Add Patient
void addPatient()
{
    printf("\nEnter Patient ID: ");
    scanf("%d", &patients[patientCount].patientID);

    printf("Enter Patient Name: ");
    scanf(" %[^\n]", patients[patientCount].name);

    printf("Enter Age: ");
    scanf("%d", &patients[patientCount].age);

    printf("Enter Disease: ");
    scanf(" %[^\n]", patients[patientCount].disease);

    patientCount++;

    printf("\nPatient Added Successfully!\n");
}

// View Patients
void viewPatients()
{
    if(patientCount==0)
    {
        printf("\nNo Patient Found!\n");
        return;
    }

    printf("\n------ Patient List ------\n");

    for(int i=0;i<patientCount;i++)
    {
        printf("\nPatient %d\n",i+1);
        printf("ID      : %d\n",patients[i].patientID);
        printf("Name    : %s\n",patients[i].name);
        printf("Age     : %d\n",patients[i].age);
        printf("Disease : %s\n",patients[i].disease);
    }
}

// Search Patient
void searchPatient()
{
    int id,found=0;

    printf("Enter Patient ID: ");
    scanf("%d",&id);

    for(int i=0;i<patientCount;i++)
    {
        if(patients[i].patientID==id)
        {
            printf("\nPatient Found!\n");
            printf("ID      : %d\n",patients[i].patientID);
            printf("Name    : %s\n",patients[i].name);
            printf("Age     : %d\n",patients[i].age);
            printf("Disease : %s\n",patients[i].disease);

            found=1;
            break;
        }
    }

    if(found==0)
        printf("\nPatient Not Found!\n");
}

// Delete Patient
void deletePatient()
{
    int id,index=-1;

    printf("Enter Patient ID: ");
    scanf("%d",&id);

    for(int i=0;i<patientCount;i++)
    {
        if(patients[i].patientID==id)
        {
            index=i;
            break;
        }
    }

    if(index==-1)
    {
        printf("\nPatient Not Found!\n");
        return;
    }

    for(int i=index;i<patientCount-1;i++)
    {
        patients[i]=patients[i+1];
    }

    patientCount--;

    printf("\nPatient Deleted Successfully!\n");
}