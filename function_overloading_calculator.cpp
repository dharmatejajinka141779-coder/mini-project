#include <iostream>
#include <cmath>
using namespace std;

int add(int a, int b)
{
    return a + b;
}

double add(double a, double b)
{
    return a + b;
}

int multiply(int a, int b)
{
    return a * b;
}

double multiply(double a, double b)
{
    return a * b;
}

int square(int n)
{
    return n * n;
}

double square(double n)
{
    return n * n;
}

int cube(int n)
{
    return n * n * n;
}

double squareroot(double n)
{
    if(n < 0)
    {
        cout << "Negative number not allowed\n";
        return 0;
    }
    return sqrt(n);
}

int factorial(int n)
{
    int fact = 1;
    for(int i = 1; i <= n; i++)
        fact *= i;
    return fact;
}

bool isprime(int n)
{
    if(n <= 1)
        return false;

    for(int i = 2; i * i <= n; i++)
        if(n % i == 0)
            return false;

    return true;
}

int digitsum(long long n)
{
    int sum = 0;
    while(n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main()
{
    int num;
    cout << "Enter number: ";
    cin >> num;

    cout << "Factorial: " << factorial(num) << endl;
    cout << "Prime check: " << (isprime(num) ? "Prime" : "Not Prime") << endl;
    cout << "Digit Sum: " << digitsum(num) << endl;
    cout << "Square: " << square(num) << endl;
    cout << "Cube: " << cube(num) << endl;
    cout << "Square Root: " << squareroot(num) << endl;

    int a, b;
    cout << "\nEnter two integers: ";
    cin >> a >> b;

    cout << "Addition: " << add(a, b) << endl;
    cout << "Multiplication: " << multiply(a, b) << endl;

    double x, y;
    cout << "\nEnter two decimal numbers: ";
    cin >> x >> y;

    cout << "Addition : " << add(x, y) << endl;
    cout << "Multiplication : " << multiply(x, y) << endl;

    return 0;
}
