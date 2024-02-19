#include <iostream>
#include <cmath>

using namespace std;

class Polygon {
public:
    virtual double area() = 0;
};

class Circle : public Polygon {
private:
    double radius;
public:
    Circle(double r) {
        radius = r;
    }
    double area() {
        return M_PI * pow(radius, 2);
    }
};

class Rectangle : public Polygon {
private:
    double length, width;
public:
    Rectangle(double l, double w) {
        length = l;
        width = w;
    }
    double area() {
        return length * width;
    }
};
class Triangle : public Polygon {
private:
    double base, height;
public:
    Triangle(double b, double h) {
        base = b;
        height = h;
    }
    double area() {
        return 0.5 * base * height;
    }
};

class Square : public Polygon {
private:
    double side;
public:
    Square(double s) {
        side = s;
    }
    double area() {
        return pow(side, 2);
    }
};

int main() {
    int choice;
    cout << "Choose the polygon to calculate the area: \n";
    cout << "1. Circle\n";
    cout << "2. Rectangle\n";
    cout << "3. Triangle\n";
    cout << "4. Square\n";

    cin >> choice;

    switch (choice) {
        case 1: {
            double radius;
            cout << "Enter the radius of the circle: ";
            cin >> radius;
            Circle c(radius);
            cout << "Area of the circle is: " << c.area() << endl;
            break;
        }
        case 2: {
            double length, width;
            cout << "Enter the length and width of the rectangle: ";
            cin >> length >> width;
            Rectangle r(length, width);
            cout << "Area of the rectangle is: " << r.area() << endl;
            break;
        }
          case 3: {
            double base, height;
            cout << "Enter the base and height of triangle: ";
            cin >> base>>height;
            Triangle t(base, height);
            cout << "Area of the triangle is: " << t.area() << endl;
            break;
        }
         case 4: {
            double side;
            cout << "Enter the side of square: ";
            cin >> side;
            Square s(side);
            cout << "Area of the square is: " << s.area() << endl;
            break;
        }
        default:
            cout << "Invalid choice" << endl;
    }

    return 0;
}