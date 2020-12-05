#include <iostream>
#include <conio.h>
#include <stdio.h>

class  Point {
public:
    int x, y;
    Point() {
        printf("Point()\n");
        x = 0;
        y = 0;
    }
    Point(int x, int y) {
        printf("Point(int x, int y)\n");
        this->x = x;
        this->y = y;
    }
    Point(const Point& p) {
        printf("Point(const Point& p)\n");
        x = p.x;
        y = p.y;
    }
    virtual ~Point() { 
        printf("%d,%d\n", x, y);
        printf("~Point()\n");
        printf("\n");
    }
    void change_value(int a, int b) {
        x = a;
        y = b;
    }
    void reverse();
};

void Point::reverse() {
    x = -x;
    y = -y;
}



class ColoredPoint: public Point{
protected:
    int color;
private: 
    ColoredPoint(const ColoredPoint& p) {
        printf("ColoredPoint(const ColoredPoint& p)\n");
        x = p.x;
        y = p.y;
        color = p.color;
    }
public:
    ColoredPoint() :Point() {
        printf("ColoredPoint()\n");
        color = 0;
    }
    ColoredPoint(int x, int y, int color) :Point(x,y) {
        printf("ColoredPoint(int x, int y)\n");
        this->color = color;

    }

    ~ColoredPoint() {
        printf("%d,%d,%d\n", x, y,color);
        printf("~ColoredPoint()\n");
        printf("\n");
    }
    void change_color(int new_color) {
        color = new_color;
    }
};

class Section {
protected:
    Point* p1;
    Point* p2;
public:
    Section() {
        printf("Section()\n");
        p1 = new Point;
        p2 = new Point;
    }
    Section(int x1, int y1, int x2, int y2) {
        printf("Section(int x, int y)\n");
        p1 = new Point(x1, y1);
        p2 = new Point(x2, y2);
    }
    Section(const Section& s) {
        printf("Section(const Section& p)\n");
        p1 = new Point (*(s.p1));
        p2 = new Point (*(s.p2));
    }
    ~Section() {
        delete p1;
        delete p2;
        printf("~Section()\n");
    }
};



int main() {
    {
        Point p;
        Point p2(10, 20);
        Point p3(p2);
        printf("\n");
    }

    Point* p = new Point;
    Point* p2 = new Point(10, 20);
    p2->change_value(10, 10);
    p2->reverse();

    Point* p3 = new Point(*p2);
    printf("\n");

    delete p;
    delete p2;
    delete p3;

    ColoredPoint* p4 = new ColoredPoint(10, 11, 22);
    delete p4;

    Point* p5 = new ColoredPoint(1, 2, 3);
    delete p5;

    Section* s1 = new Section;
    Section* s2 = new Section(*s1);

    delete s1;
    delete s2;

    _getch();
    return 0;

}