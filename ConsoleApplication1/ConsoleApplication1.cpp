#include <iostream>
#include <conio.h>
#include <stdio.h>

class  Object {
public:
    int x, y;
    Object() {
        printf("Object()\n");
        x = 0;
        y = 0;
    }
    Object(int x, int y) {
        printf("Object(int x, int y)\n");
        this->x = x;
        this->y = y;
    }
    Object(const Object& p) {
        printf("Object(const Object& p)\n");
        x = p.x;
        y = p.y;
    }
    virtual ~Object() {
        printf("%d,%d\n", x, y);
        printf("~Object()\n");
        printf("\n");
    }
    void change_value(int a, int b) {
        x = a;
        y = b;
    }
    void reverse();
};

void Object::reverse() {
    x = -x;
    y = -y;
}



class Subject: public Object {
protected:
    int z;
private: 
    Subject(const Subject& p) {
        printf("Subject(const Subject& p)\n");
        x = p.x;
        y = p.y;
        z = p.z;
    }
public:
    Subject() :Object() {
        printf("Subject()\n");
        z = 0;
    }
    Subject(int x, int y, int z) :Object(x,y) {
        printf("Subject(int x, int y)\n");
        this->z = z;

    }

    ~Subject() {
        printf("%d,%d,%d\n", x, y,z);
        printf("~Subject()\n");
        printf("\n");
    }
    void change_z(int new_z) {
        z = new_z;
    }
};

class Section {
protected:
    Object* p1;
    Object* p2;
public:
    Section() {
        printf("Section()\n");
        p1 = new Object;
        p2 = new Object;
    }
    Section(int x1, int y1, int x2, int y2) {
        printf("Section(int x, int y)\n");
        p1 = new Object(x1, y1);
        p2 = new Object(x2, y2);
    }
    Section(const Section& s) {
        printf("Section(const Section& p)\n");
        p1 = new Object(*(s.p1));
        p2 = new Object(*(s.p2));
    }
    ~Section() {
        delete p1;
        delete p2;
        printf("~Section()\n");
    }
};



int main() {
    {
        Object p;
        Object p2(10, 20);
        Object p3(p2);
        printf("\n");
    }

    Object* p = new Object;
    Object* p2 = new Object(10, 20);
    p2->change_value(10, 10);
    p2->reverse();

    Object* p3 = new Object(*p2);
    printf("\n");

    delete p;
    delete p2;
    delete p3;

    Subject* p4 = new Subject(10, 11, 22);
    delete p4;

    Object* p5 = new Subject(1, 2, 3);
    delete p5;

    Section* s1 = new Section;
    Section* s2 = new Section(*s1);

    delete s1;
    delete s2;

    _getch();
    return 0;

}