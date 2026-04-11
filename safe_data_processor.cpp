#include <iostream>
#include <vector>
#include <stdexcept>
#include <limits>
using namespace std;

template <typename T>
class DataProcessor {
private:
    vector<T> data;

public:
    void addData(const T& value) {
        if (value == "") {
            throw invalid_argument("Empty input not allowed!");
        }
        data.push_back(value);
    }

    void processData() {
        if (data.empty()) {
            throw runtime_error("No data to process!");
        }

        for (auto &val : data) {
            for (auto &ch : val) {
                ch = toupper(ch);
            }
        }
    }

    void display() {
        cout << "\nStored Data:\n";
        for (const auto &val : data) {
            cout << val << endl;
        }
    }
};

template <>
class DataProcessor<int> {
private:
    vector<int> data;

public:
    void addData(int value) {
        data.push_back(value);
    }

    void processData() {
        if (data.empty()) throw runtime_error("No data!");

        for (auto &val : data) {
            val = val * val;
        }
    }

    void display() {
        cout << "\nProcessed Numbers:\n";
        for (auto val : data) {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main() {
    int choice, typeChoice;

    cout << "Select Data Type:\n1. Numbers\n2. Text (Names/Paragraph)\nChoice: ";
    cin >> typeChoice;
    cin.ignore(); 

    try {
        if (typeChoice == 1) {
            DataProcessor<int> dp;
            int value;

            do {
                cout << "\n1.Add 2.Process 3.Display 4.Exit\nChoice: ";
                cin >> choice;

                switch (choice) {
                    case 1:
                        cout << "Enter number: ";
                        cin >> value;

                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(1000, '\n');
                            throw invalid_argument("Invalid number!");
                        }

                        dp.addData(value);
                        break;

                    case 2:
                        dp.processData();
                        cout << "Processed.\n";
                        break;

                    case 3:
                        dp.display();
                        break;
                }
            } while (choice != 4);
        }

        else if (typeChoice == 2) {
            DataProcessor<string> dp;
            string input;

            do {
                cout << "\n1.Add 2.Process 3.Display 4.Exit\nChoice: ";
                cin >> choice;
                cin.ignore();

                switch (choice) {
                    case 1:
                        cout << "Enter text (name/paragraph): ";
                        getline(cin, input);

                        dp.addData(input);
                        break;

                    case 2:
                        dp.processData();
                        cout << "Converted to UPPERCASE.\n";
                        break;

                    case 3:
                        dp.display();
                        break;
                }
            } while (choice != 4);
        }

        else {
            throw invalid_argument("Invalid type selection!");
        }
    }
    catch (exception &e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
