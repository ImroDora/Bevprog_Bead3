#ifndef WIDGET_H
#define WIDGET_H
#include <iostream>
#include <vector>
#include <string>
#include "graphics.hpp"

using namespace genv;
using namespace std;

struct Point {
    int x;
    int y;
    Point(int a,int b){
    x=a;
    y=b;
    }
    Point():Point(0,0){}
};

struct Size {
    int w;
    int h;
    Size(int a,int b){
    w=a;
    h=b;
    }
    Size():Size(0,0){}
};

/*
Size meret;
meret.w=5;
meret.h=4;
Size mmeret(5,4);
*/

class Widget {
private:
    Point pos;
    Size size;
    int szamertek;
    string cim;

public:
    Widget(Point pos_ = { 0, 0 }, Size size_ = { 0, 0 });
    virtual ~Widget();

    virtual void draw();
    virtual void change_value(event evt);

    Point get_pos() const;
    void set_pos(Point new_pos);

    Size get_size() const;
    void set_size(Size new_size);
};

#endif // WIDGET_H
