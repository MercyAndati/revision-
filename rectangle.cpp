#include <iostream>
using namespace std;

class Rectangle {
private:
    double width;
    double height;
public:
    Rectangle() {
        width = 0;
        height = 0;
    }
    Rectangle(double w, double h) {
        width = w;
        height = h;
    }
    double calculateArea() {
        return width * height;
    }
    void display() {
        cout << "Width: " << width << endl;
        cout << "Height: " << height << endl;
        cout << "Area: " << calculateArea() << endl;
    }
};

int main() {
    Rectangle r1; 
    Rectangle r2(3, 4); 
    r1.display(); 
    r2.display(); 
    return 0;
}