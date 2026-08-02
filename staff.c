#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "staff.h"

void addStaff() {
    struct Staff s;
    FILE *f = fopen("staff.txt", "a");
    if (!f) { printf("File error!\n"); return; }
    
    printf("Enter Staff ID: "); scanf("%d", &s.id);
    printf("Enter Name: "); scanf(" %[^\n]", s.name);
    printf("Enter Position: "); scanf(" %[^\n]", s.position);
    printf("Enter Salary: "); scanf("%f", &s.salary);
    printf("Enter Phone: "); scanf(" %[^\n]", s.phone);
    
    fprintf(f, "%d %s %s %.2f %s\n", s.id, s.name, s.position, s.salary, s.phone);
    fclose(f);
    printf("Staff added successfully!\n");
}

void viewAllStaff() {
    struct Staff s;
    FILE *f = fopen("staff.txt", "r");
    if (!f) { printf("No staff found.\n"); return; }
    
    printf("\n====== STAFF LIST ======\n");
    while (fscanf(f, "%d %s %s %f %s", &s.id, s.name, s.position, &s.salary, s.phone) == 5) {
        printf("ID: %d | Name: %s | Position: %s | Salary: %.2f | Phone: %s\n",
               s.id, s.name, s.position, s.salary, s.phone);
    }
    fclose(f);
}
void searchStaff() {
    struct Staff s;
    int searchId, found = 0;
    FILE *f = fopen("staff.txt", "r");
    if (!f) { 
        printf("No staff found.\n"); 
        return; 
    }

    printf("Enter Staff ID to search: ");
    scanf("%d", &searchId);

    while (fscanf(f, "%d %s %s %f %s", &s.id, s.name, s.position, &s.salary, s.phone) == 5) {
        if (s.id == searchId) {
            printf("\n--- Staff Found! ---\n");
            printf("ID: %d | Name: %s | Position: %s | Salary: %.2f | Phone: %s\n", 
                   s.id, s.name, s.position, s.salary, s.phone);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Staff with ID %d not found!\n", searchId);
    }
    fclose(f);
}
void staffMenu() {
    int choice;
    while(1) {
        printf("\n===== STAFF MENU =====\n");
        printf("1. Add Staff\n");
        printf("2. View All Staff\n");
        printf("3. Search Staff\n");
        printf("4. Back\n");
        printf("Enter Choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: addStaff(); break;
            case 2: viewAllStaff(); break;
            case 3: searchStaff(); break;
            case 4: return;
            default: printf("Invalid Choice!\n");
        }
    }
}
