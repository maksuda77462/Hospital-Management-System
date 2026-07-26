 #include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pharmacy.h"

void addMedicine() {
    struct Medicine m;
    FILE *f = fopen("medicines.txt", "a");
    if (!f) { printf("File error!\n"); return; }
    printf("Enter Medicine ID: "); scanf("%d", &m.id);
    printf("Enter Medicine Name: "); scanf(" %[^\n]", m.name);
    printf("Enter Quantity: "); scanf("%d", &m.quantity);
    printf("Enter Price: "); scanf("%f", &m.price);
    fprintf(f, "%d %s %d %.2f\n", m.id, m.name, m.quantity, m.price);
    fclose(f);
    printf("Medicine added successfully!\n");
}

void viewAllMedicines() {
    struct Medicine m;
    FILE *f = fopen("medicines.txt", "r");
    if (!f) { printf("No medicines found.\n"); return; }
    printf("\n===== MEDICINE LIST =====\n");
    while (fscanf(f, "%d %s %d %f", &m.id, m.name, &m.quantity, &m.price) != EOF) {
        printf("ID: %d | Name: %s | Stock: %d | Price: %.2f\n", 
               m.id, m.name, m.quantity, m.price);
    }
    fclose(f);
}