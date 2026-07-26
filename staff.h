#ifndef STAFF_H
#define STAFF_H

struct Staff {
    int id;
    char name[50];
    char position[50];
    float salary;
    char phone[15];
};

void addStaff();
void viewAllStaff();
void staffMenu();

#endif
