 #ifndef PHARMACY_H
#define PHARMACY_H

struct Medicine {
    int id;
    char name[50];
    int quantity;
    float price;
};

void addMedicine();
void viewAllMedicines()
void searchMedicine();
void pharmacyMenu();
#endif
