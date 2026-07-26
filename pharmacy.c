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
    
    printf("\n====== MEDICINE LIST ======\n");
    while (fscanf(f, "%d %s %d %f", &m.id, m.name, &m.quantity, &m.price) == 4) {
        printf("ID: %d | Name: %s | Stock: %d | Price: %.2f\n",
               m.id, m.name, m.quantity, m.price);
    }
    fclose(f);
}

void pharmacyMenu() {
    int choice;
    while(1) {
        printf("\n===== PHARMACY MENU =====\n");
        printf("1. Add Medicine\n");
        printf("2. View All Medicines\n");
        printf("3. Back\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: addMedicine(); break;
            case 2: viewAllMedicines(); break;
            case 3: return;
            default: printf("Invalid Choice!\n");
        }
    }
}
