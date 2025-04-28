#include <iostream>
#define PI 3.141592653589793


class ThreeDimensionalShape {
    int coordinateX;
    int coordinateY;
    int coordinateZ;
    public:

    ThreeDimensionalShape() {
        coordinateX = 0;
        coordinateY = 0;
        coordinateZ = 0;
    }

    ThreeDimensionalShape(int x, int y, int z) {
        coordinateX = x;
        coordinateY = y;
        coordinateZ = z;
    }

    virtual double getArea() = 0;
    virtual double getVolume() = 0;
};

class Sphere: public ThreeDimensionalShape {

    double radius;

    public:

    Sphere() {
        radius = 0;
    }

    Sphere(int x, int y, int z, double r):ThreeDimensionalShape(x,y,z) {
        radius = r;
    }

    double getArea() override {
        return PI * radius * radius;
    }

    double getVolume() override {
        return PI * radius * radius * radius * 4 / 3;
    }
};

class Cylinder: public ThreeDimensionalShape {
    double radius = 0;
    double height = 0;

    public:
    Cylinder(double _radius, double _height){
        radius = _radius;
        height = _height;
    }

    double getArea() override {
        return PI * radius * (radius+height) * 2;
    }

    double getVolume() override {
        return PI * radius * radius * height;
    }
};

void printShape(ThreeDimensionalShape* ts) {

    std::cout << "typeid: " << typeid(*ts).name() << std::endl;
    std::cout << "Area: " << ts->getArea() << std::endl;
    std::cout << "Volume: " << ts->getVolume() << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

}

int main() {

    Sphere  s (1, 1, 1, 4.5);
    Cylinder *c = new Cylinder(3, 3.2);
    Cylinder cy(2, 7);

    printShape(&s);
    printShape(c);
    printShape(&cy);
}