#include "Widget.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include "graphics.hpp"

using namespace genv;
using namespace std;

Widget::Widget(Point pos_, Size size_):
    pos(pos_),
    size(size_)
{

}

Widget::~Widget(){}

void Widget::draw()
{

}

void Widget::change_value(genv::event ev){
}

Point Widget::get_pos() const {
    return pos;
}

void Widget::set_pos(Point new_pos) {
    pos = new_pos;
}

Size Widget::get_size() const {
    return size;
}

void Widget::set_size(Size new_size) {
    size = new_size;
}
