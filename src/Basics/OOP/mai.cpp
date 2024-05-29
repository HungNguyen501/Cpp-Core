#include <iostream>
using namespace std;

class Shape{
private:
    string name;
public:
    Shape() {
        // Defualt constructor
    }

    void setName(string name) {
        this->name = name;
    }

    string getName(){
        return name;
    }

    virtual void printInfo() {return;};
    virtual int area() {return 0;};
};

class Rectangle : public Shape {
private:
    int length, width;
public:

    Rectangle() {
        // Default constructor
    }

    Rectangle(int length, int width) {
        this->length = length;
        this->width = width;
        this->setName("Rectangle");
    }

    void printInfo() {
        cout << "This is " << this->getName() << endl;
    }

    int area() {
        return length*width;
    }

    int area(int index) {
        return length*width*index;
    }

    void volume() {
        cout << "volume is 123" << endl;
    }
};

int main() {
    Shape *s = new Rectangle(5,2);
    Rectangle r1(5,2);
    r1.volume();

    Shape *s1 = &r1;
    s1->printInfo();

    s->printInfo();

    long a = 100;
    int x = a;
    int c = 10;
    long d = c;
    cout << x << endl;
   

    system("Pause");
    return 0;
}