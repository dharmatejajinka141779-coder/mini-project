#include <iostream>
using namespace std;

class Student
{
private:
    string name;
    string enrollmentNo;
    string className;
    string batch;
    string mobileNumber;

public:
    void input()
    {
        cout << "Enter Name: ";
        getline(cin >> ws, name);

        cout << "Enter Enrollment Number: ";
        cin >> enrollmentNo;

        cout << "Enter Class Name: ";
        cin >> className;

        cout << "Enter Batch (e.g., 2026-2029): ";
        cin >> batch;

        while(true)
        {
            cout << "Enter Mobile Number (10 digits): ";
            cin >> mobileNumber;

            for(int i = 0; i < mobileNumber.length(); i++)
            {
                if(mobileNumber[i] < '0' || mobileNumber[i] > '9')
                {
                    cout << "Invalid input!.\n";
                    exit(0);
                }
            }

            if(mobileNumber.length() == 10)
                break;
            else
                cout << "Mobile number must be exactly 10 digits. Re-enter.\n";
        }
    }

    void display()
    {
        cout << "\nStudent Profile\n";
        cout << "Name          : " << name << endl;
        cout << "Enrollment No : " << enrollmentNo << endl;
        cout << "Class Name    : " << className << endl;
        cout << "Batch         : " << batch << endl;
        cout << "Mobile Number : " << mobileNumber << endl;
    }
};

int main()
{
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    if(cin.fail())
    {
        cout << "Invalid input!.\n";
        return 0;
    }

    Student students[n];

    for(int i = 0; i < n; i++)
    {
        cout << "\nEnter details for Student " << i + 1 << endl;
        students[i].input();
    }

    cout << "\n----- All Student Profiles -----\n";

    for(int i = 0; i < n; i++)
    {
        students[i].display();
    }

    return 0;
}
