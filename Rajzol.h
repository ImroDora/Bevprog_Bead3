#ifndef RAJZOL_H
#define RAJZOL_H
#include "graphics.hpp"
#include "Widget.h"

using namespace std;
using namespace genv;

class Rajzol: public Widget
{
public:
    Rajzol();
    virtual ~Rajzol();
    void full_clr();
    virtual void clr_src();
    void palya_rajz();
    void menu_rajz();
    void kor_rajz(int korszam);
    void rules_rajz();
    void green_rajz(event evt, Rajzol felulet, Point a, Size b, int i, int j);
    void blue_rajz(event evt, Rajzol felulet, Point a, Size b, int i, int j);
    void telepalya_rajz();
    void zoldgyozelem_rajz();
    void kekgyozelem_rajz();

protected:

private:
    int korszam;
};

#endif // RAJZOL_H
