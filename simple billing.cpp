#include <iostream>
using namespace std;

int main() {
    int numItems;
    double price, total = 0, tax, finalTotal;
    
    cout << "=== WELCOME TO X ===" << endl;
    cout << "Enter number of items: ";
    
    if(!(cin >> numItems)) {
        cout << "\nERROR: Please enter a number!" << endl;
        return 0;
    }
    for(int i = 1; i <= numItems; i++) {
        cout << "Enter price for item " << i << ": ?";
        if(!(cin >> price)) {
            cout << "\nERROR: Please enter a number for price!" << endl;
            return 0;
        }
        
        total += price; 
    }
    tax = total * 0.18;
    finalTotal = total + tax;

    cout << "\n=== BILL SUMMARY ===" << endl;
    cout << "Total items: " << numItems << endl;
    cout << "Subtotal: ?" << total << endl;
    cout << "Tax (18%): ?" << tax << endl;
    cout << "Final Total: ?" << finalTotal << endl;
    cout << "=====================" << endl;
    
    cout << "\nThank you! VISIT AGAIN ??" << endl;
    return 0;
}
