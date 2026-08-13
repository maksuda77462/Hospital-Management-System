#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pharmacy
{
    int medicineId;
    char medicineName[50];
    int quantity;
    float price;
};

void addMedicine()
{
    struct Pharmacy m;
    FILE *fp;

    fp = fopen("medicine.txt", "a");

    if(fp == NULL)
    {
        printf("\nFile cannot be opened!");
        return;
    }

    printf("\n===== ADD MEDICINE =====");

    printf("\nMedicine ID: ");
    scanf("%d", &m.medicineId);

    printf("Medicine Name: ");
    scanf(" %[^\n]", m.medicineName);

    printf("Quantity: ");
    scanf("%d", &m.quantity);

    printf("Price: ");
    scanf("%f", &m.price);

    fprintf(fp, "%d %s %d %.2f\n",
            m.medicineId,
            m.medicineName,
            m.quantity,
            m.price);

    fclose(fp);

    printf("\nMedicine Added Successfully!\n");
}

void viewMedicine()
{
    struct Pharmacy m;
    FILE *fp;

    fp = fopen("medicine.txt", "r");

    if(fp == NULL)
    {
        printf("\nNo medicine record found!");
        return;
    }

    printf("\n===== MEDICINE RECORD =====");

    while(fscanf(fp, "%d %s %d %f",
                 &m.medicineId,
                 m.medicineName,
                 &m.quantity,
                 &m.price) != EOF)
    {
        printf("\n\nMedicine ID: %d", m.medicineId);
        printf("\nMedicine Name: %s", m.medicineName);
        printf("\nQuantity: %d", m.quantity);
        printf("\nPrice: %.2f", m.price);
    }

    fclose(fp);
}

void searchMedicine()
{
    struct Pharmacy m;
    FILE *fp;
    int id;
    int found = 0;

    fp = fopen("medicine.txt", "r");

    if(fp == NULL)
    {
        printf("\nNo medicine record found!");
        return;
    }

    printf("\nEnter Medicine ID: ");
    scanf("%d", &id);

    while(fscanf(fp, "%d %s %d %f",
                 &m.medicineId,
                 m.medicineName,
                 &m.quantity,
                 &m.price) != EOF)
    {
        if(m.medicineId == id)
        {
            printf("\n===== MEDICINE FOUND =====");
            printf("\nMedicine ID: %d", m.medicineId);
            printf("\nMedicine Name: %s", m.medicineName);
            printf("\nQuantity: %d", m.quantity);
            printf("\nPrice: %.2f", m.price);

            found = 1;
            break;
        }
    }

    if(found == 0)
    {
        printf("\nMedicine Not Found!");
    }

    fclose(fp);
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n\n===== PHARMACY MANAGEMENT =====");

        printf("\n1. Add Medicine");
        printf("\n2. View Medicine");
        printf("\n3. Search Medicine");
        printf("\n4. Exit");

        printf("\n\nChoice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addMedicine();
                break;

            case 2:
                viewMedicine();
                break;

            case 3:
                searchMedicine();
                break;

            case 4:
                exit(0);

            default:
                printf("\nInvalid Choice!");
        }
    }

    return 0;
}
