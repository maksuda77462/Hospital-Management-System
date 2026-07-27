#include <stdio.h>
#include <string.h>
#include "doctor.h"

struct Doctor doctors[MAX];
int doctorCount = 0;

// Add Doctor
void addDoctor()
{
    printf("\nEnter Doctor ID: ");
    scanf("%d",&doctors[doctorCount].doctorID);

    printf("Enter Doctor Name: ");
    scanf(" %[^\n]",doctors[doctorCount].name);

    printf("Enter Specialization: ");
    scanf(" %[^\n]",doctors[doctorCount].specialization);

    doctorCount++;

    printf("\nDoctor Added Successfully!\n");
}

// View Doctors
void viewDoctors()
{
    if(doctorCount==0)
    {
        printf("\nNo Doctor Found!\n");
        return;
    }

    printf("\n------ Doctor List ------\n");

    for(int i=0;i<doctorCount;i++)
    {
        printf("\nDoctor %d\n",i+1);
        printf("ID             : %d\n",doctors[i].doctorID);
        printf("Name           : %s\n",doctors[i].name);
        printf("Specialization : %s\n",doctors[i].specialization);
    }
}

// Search Doctor
void searchDoctor()
{
    int id,found=0;

    printf("Enter Doctor ID: ");
    scanf("%d",&id);

    for(int i=0;i<doctorCount;i++)
    {
        if(doctors[i].doctorID==id)
        {
            printf("\nDoctor Found!\n");
            printf("ID             : %d\n",doctors[i].doctorID);
            printf("Name           : %s\n",doctors[i].name);
            printf("Specialization : %s\n",doctors[i].specialization);

            found=1;
            break;
        }
    }

    if(found==0)
        printf("\nDoctor Not Found!\n");
}

// Delete Doctor
void deleteDoctor()
{
    int id,index=-1;

    printf("Enter Doctor ID: ");
    scanf("%d",&id);

    for(int i=0;i<doctorCount;i++)
    {
        if(doctors[i].doctorID==id)
        {
            index=i;
            break;
        }
    }

    if(index==-1)
    {
        printf("\nDoctor Not Found!\n");
        return;
    }

    for(int i=index;i<doctorCount-1;i++)
    {
        doctors[i]=doctors[i+1];
    }

    doctorCount--;

    printf("\nDoctor Deleted Successfully!\n");
}