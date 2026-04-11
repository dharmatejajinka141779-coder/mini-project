#include <iostream>
#include <cmath>
using namespace std;

class Point
{
public:
    float x,y;

    void input()
    {
        cout<<"Enter x y : ";
        cin>>x>>y;
    }

    Point operator+(Point p)
    {
        Point t;
        t.x = x + p.x;
        t.y = y + p.y;
        return t;
    }

    Point operator-(Point p)
    {
        Point t;
        t.x = x - p.x;
        t.y = y - p.y;
        return t;
    }

    void display()
    {
        cout<<"("<<x<<","<<y<<")"<<endl;
    }
};

class Line
{
public:
    Point p1,p2;

    float length()
    {
        return sqrt(pow(p2.x-p1.x,2)+pow(p2.y-p1.y,2));
    }
};

class Triangle
{
public:
    Point p1,p2,p3;

    float area()
    {
        return 0.5 * abs(
        p1.x*(p2.y-p3.y) +
        p2.x*(p3.y-p1.y) +
        p3.x*(p1.y-p2.y));
    }
};

class Rectangle
{
public:
    Point p1,p2;

    float area()
    {
        float length = abs(p2.x-p1.x);
        float width  = abs(p2.y-p1.y);
        return length * width;
    }
};

class Square
{
public:
    Point p1,p2;

    float area()
    {
        float side = sqrt(pow(p2.x-p1.x,2)+pow(p2.y-p1.y,2));
        return side * side;
    }
};

class Circle
{
public:
    Point center, p;

    float area()
    {
        float r = sqrt(pow(p.x-center.x,2)+pow(p.y-center.y,2));
        return 3.14*r*r;
    }
};

int main()
{
    Point p1,p2,p3;

    cout<<"Enter Point 1
";
    p1.input();

    cout<<"Enter Point 2
";
    p2.input();

    Point p = p1 + p2;
    cout<<"Addition : ";
    p.display();

    p = p1 - p2;
    cout<<"Subtraction : ";
    p.display();

    Line L;
    L.p1=p1;
    L.p2=p2;
    cout<<"Length of line : "<<L.length()<<endl;

    Triangle t;
    cout<<"Enter triangle points
";
    t.p1.input();
    t.p2.input();
    t.p3.input();
    cout<<"Area of triangle : "<<t.area()<<endl;

    Rectangle r;
    cout<<"Enter rectangle diagonal points
";
    r.p1.input();
    r.p2.input();
    cout<<"Area of rectangle : "<<r.area()<<endl;

    Square s;
    cout<<"Enter square diagonal points
";
    s.p1.input();
    s.p2.input();
    cout<<"Area of square : "<<s.area()<<endl;

    Circle c;
    cout<<"Enter circle center
";
    c.center.input();
    cout<<"Enter point on circle
";
    c.p.input();
    cout<<"Area of circle : "<<c.area()<<endl;

    return 0;
}
