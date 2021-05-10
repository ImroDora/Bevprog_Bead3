#ifndef RAJZOL_H
#define RAJZOL_H
#include "graphics.hpp"
#include "Widget.h"

using namespace std;
using namespace genv;

class Rajzol: public Widget
{
public:
    Rajzol(int kor_szam);
    virtual ~Rajzol();
    virtual void clr_src();
    void palya_rajz();
    void menu_rajz();
    void kor_rajz();
    void rules_rajz();
    void green_rajz(event evt, Rajzol felulet);
    void blue_rajz(event evt, Rajzol felulet);

    int get_kor() const;
    void set_kor(int new_kor);

protected:

private:
    int korszam;
};

#endif // RAJZOL_H
