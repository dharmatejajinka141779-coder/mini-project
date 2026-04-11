#include <iostream>
using namespace std;

class Employee {
protected:
    string name;
    double baseSalary;
    int overtimeHours;
    double overtimeRate;

public:
    Employee(string n, double salary, int otH = 0, double otR = 0) {
        name = n;
        baseSalary = salary;
        overtimeHours = otH;
        overtimeRate = otR;
    }

    virtual double calculateSalary() {
        return baseSalary + (overtimeHours * overtimeRate);
    }

    virtual string getRole() {
        return "Employee";
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Designation: " << getRole() << endl;
        cout << "Salary: " << calculateSalary() << endl;
    }
};

class Manager : public Employee {
    double bonus;
public:
    Manager(string n, double s, double b, int otH = 0, double otR = 0)
        : Employee(n, s, otH, otR), bonus(b) {}

    double calculateSalary() override {
        return baseSalary + bonus + (overtimeHours * overtimeRate);
    }

    string getRole() override {
        return "Manager";
    }
};

class Developer : public Employee {
public:
    Developer(string n, double s, int h, double r)
        : Employee(n, s, h, r) {}

    string getRole() override {
        return "Developer";
    }
};

class Intern : public Employee {
public:
    Intern(string n, double stipend, int otH = 0, double otR = 0)
        : Employee(n, stipend, otH, otR) {}

    string getRole() override {
        return "Intern";
    }
};

class HR : public Employee {
    double allowance;
public:
    HR(string n, double s, double a, int otH = 0, double otR = 0)
        : Employee(n, s, otH, otR), allowance(a) {}

    double calculateSalary() override {
        return baseSalary + allowance + (overtimeHours * overtimeRate);
    }

    string getRole() override {
        return "HR";
    }
};

class Salesperson : public Employee {
    double commission;
public:
    Salesperson(string n, double s, double c, int otH = 0, double otR = 0)
        : Employee(n, s, otH, otR), commission(c) {}

    double calculateSalary() override {
        return baseSalary + commission + (overtimeHours * overtimeRate);
    }

    string getRole() override {
        return "Salesperson";
    }
};

class TeamLead : public Employee {
    double teamBonus;
public:
    TeamLead(string n, double s, double tb, int otH = 0, double otR = 0)
        : Employee(n, s, otH, otR), teamBonus(tb) {}

    double calculateSalary() override {
        return baseSalary + teamBonus + (overtimeHours * overtimeRate);
    }

    string getRole() override {
        return "TeamLead";
    }
};

int main() {
    Manager m("Aryan", 50000, 10000, 5, 1000);
    Developer d("Bharath", 40000, 10, 600);
    Intern i("Aadil", 15000, 2, 400);
    HR h("Vishal", 30000, 5000, 3, 1200);
    Salesperson s("Tharun", 25000, 8000, 4, 500);
    TeamLead t("Virat", 45000, 12000, 6, 800);

    m.display(); cout << endl;
    d.display(); cout << endl;
    i.display(); cout << endl;
    h.display(); cout << endl;
    s.display(); cout << endl;
    t.display();

    return 0;
}
