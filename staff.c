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
    printf("\n===== STAFF LIST =====\n");
    while (fscanf(f, "%d %s %s %f %s", &s.id, s.name, s.position, &s.salary, s.phone) != EOF) {
        printf("ID: %d | Name: %s | Position: %s | Salary: %.2f | Phone: %s\n", 
               s.id, s.name, s.position, s.salary, s.phone);
    }
    fclose(f);
}