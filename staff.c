#include <stdio.h>
#include <stdlib.h>

struct Staff
{
    int staffId;
    char name[50];
    char designation[50];
    char phone[20];
    float salary;
};

void addStaff()
{
    struct Staff s;
    FILE *fp;

    fp = fopen("staff.txt", "a");

    if (fp == NULL)
    {
        printf("\nFile cannot be opened!");
        return;
    }

    printf("\n===== ADD STAFF =====\n");

    printf("Staff ID: ");
    scanf("%d", &s.staffId);

    printf("Staff Name: ");
    scanf(" %[^\n]", s.name);

    printf("Designation: ");
    scanf(" %[^\n]", s.designation);

    printf("Phone Number: ");
    scanf("%s", s.phone);

    printf("Salary: ");
    scanf("%f", &s.salary);

    fprintf(fp, "%d|%s|%s|%s|%.2f\n",
            s.staffId,
            s.name,
            s.designation,
            s.phone,
            s.salary);

    fclose(fp);

    printf("\nStaff Added Successfully!\n");
}

void viewStaff()
{
    struct Staff s;
    FILE *fp;
    int count = 0;

    fp = fopen("staff.txt", "r");

    if (fp == NULL)
    {
        printf("\nNo staff record found!");
        return;
    }

    printf("\n====================================\n");
    printf("          STAFF RECORD\n");
    printf("====================================\n");

    while (fscanf(fp, "%d|%[^|]|%[^|]|%[^|]|%f",
                  &s.staffId,
                  s.name,
                  s.designation,
                  s.phone,
                  &s.salary) == 5)
    {
        count++;

        printf("\nStaff %d", count);
        printf("\nStaff ID    : %d", s.staffId);
        printf("\nName        : %s", s.name);
        printf("\nDesignation : %s", s.designation);
        printf("\nPhone       : %s", s.phone);
        printf("\nSalary      : %.2f\n", s.salary);
    }

    fclose(fp);

    printf("\n====================================\n");
}

void searchStaff()
{
    struct Staff s;
    FILE *fp;
    int id;
    int found = 0;

    fp = fopen("staff.txt", "r");

    if (fp == NULL)
    {
        printf("\nNo staff record found!");
        return;
    }

    printf("\n===== SEARCH STAFF =====\n");

    printf("Enter Staff ID: ");
    scanf("%d", &id);

    while (fscanf(fp, "%d|%[^|]|%[^|]|%[^|]|%f",
                  &s.staffId,
                  s.name,
                  s.designation,
                  s.phone,
                  &s.salary) == 5)
    {
        if (s.staffId == id)
        {
            printf("\nStaff Found!\n");

            printf("Staff ID    : %d\n", s.staffId);
            printf("Name        : %s\n", s.name);
            printf("Designation : %s\n", s.designation);
            printf("Phone       : %s\n", s.phone);
            printf("Salary      : %.2f\n", s.salary);

            found = 1;
            break;
        }
    }

    if (found == 0)
    {
        printf("\nStaff Not Found!\n");
    }

    fclose(fp);
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n\n====================================");
        printf("\n        STAFF MANAGEMENT");
        printf("\n====================================");

        printf("\n1. Add Staff");
        printf("\n2. View Staff");
        printf("\n3. Search Staff");
        printf("\n4. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addStaff();
            break;

        case 2:
            viewStaff();
            break;

        case 3:
            searchStaff();
            break;

        case 4:
            printf("\nThank you!\n");
            exit(0);

        default:
            printf("\nInvalid Choice!");
        }
    }

    return 0;
}
