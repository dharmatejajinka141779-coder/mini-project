#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const char* FILE_NAME = "products.dat";

class Product {
public:
    int id;
    char name[100];
    float price;
    char expiry[20];

    void input() {
        cout << "Enter ID: ";
        while (!(cin >> id)) {
            cout << "Invalid ID. Enter again: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        cin.ignore(1000, '\n');

        cout << "Enter Name: ";
        cin.getline(name, 100);

        cout << "Enter Price: ";
        while (!(cin >> price)) {
            cout << "Invalid price. Enter again: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        cin.ignore(1000, '\n');

        cout << "Enter Expiry Date (DD/MM/YYYY): ";
        cin.getline(expiry, 20);
    }

    void display() {
        cout << "ID: " << id
             << " | Name: " << name
             << " | Price: " << price
             << " | Expiry: " << expiry << endl;
    }
};

void ensureFile() {
    ofstream file(FILE_NAME, ios::binary | ios::app);
    if (!file) {
        cout << "Cannot create/open file.\n";
        exit(1);
    }
    file.close();
}

void addProduct() {
    ofstream file(FILE_NAME, ios::binary | ios::app);
    if (!file) {
        cout << "Error opening file.\n";
        return;
    }

    Product p;
    p.input();
    file.write((char*)&p, sizeof(p));

    file.close();
    cout << "Product added successfully.\n";
}

void viewProducts() {
    ifstream file(FILE_NAME, ios::binary);
    if (!file) {
        cout << "No records found.\n";
        return;
    }

    Product p;
    cout << "\n--- Product List ---\n";

    while (file.read((char*)&p, sizeof(p))) {
        p.display();
    }

    file.close();
}

void updateProduct() {
    int searchId;
    cout << "Enter Product ID to update: ";

    while (!(cin >> searchId)) {
        cout << "Invalid ID. Enter again: ";
        cin.clear();
        cin.ignore(1000, '\n');
    }

    ifstream inFile(FILE_NAME, ios::binary);
    ofstream outFile("temp.dat", ios::binary);

    if (!inFile || !outFile) {
        cout << "File error.\n";
        return;
    }

    Product p;
    bool found = false;

    while (inFile.read((char*)&p, sizeof(p))) {
        if (p.id == searchId) {
            cout << "\nExisting Record:\n";
            p.display();

            cout << "\nEnter new details:\n";
            p.input();

            found = true;
        }
        outFile.write((char*)&p, sizeof(p));
    }

    inFile.close();
    outFile.close();

    remove(FILE_NAME);
    rename("temp.dat", FILE_NAME);

    if (found)
        cout << "Product updated successfully.\n";
    else
        cout << "Product not found.\n";
}

int main() {
    ensureFile();

    int choice;

    do {
        cout << "\n===== PRODUCT MANAGEMENT =====\n";
        cout << "1. Add Product\n";
        cout << "2. View Products\n";
        cout << "3. Update Product\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Enter a number.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch (choice) {
            case 1: addProduct(); break;
            case 2: viewProducts(); break;
            case 3: updateProduct(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice\n";
        }

    } while (choice != 4);

    return 0;
}
