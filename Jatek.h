#ifndef JATEK_H
#define JATEK_H
#include <vector>
#include <graphics.hpp>
#include "Rajzol.h"
#include "Widget.h"

using namespace std;
using namespace genv;

struct Pontok: public Widget
{
    int zoldpont;
    int kekpont;
    Pontok(int zold, int kek)
    {
        zoldpont=zold;
        kekpont=kek;
    }
    Pontok():Pontok(0,0) {}
};

struct Szinezett
{
    bool zold;
    bool kek;
    int x;
    int y;
    Szinezett(bool zold_, bool kek_)
    {
        zold=zold_;
        kek=kek_;
    }
    Szinezett():Szinezett(false,false) {}
};

class Jatek
{
public:
    Jatek(int kor, int allapot, Rajzol felulet);
    virtual ~Jatek();

    void kor_vizsg(int kor, event evt, Rajzol felulet, Jatek jatek);
    void gyozelem_vizsg();
    void gyozelem(Rajzol felulet);
    void helyek_null();

    Pontok get_pontszam() const;
    void set_pontszam(Pontok new_pontszam);

    int get_allapot() const;
    void set_allapot(int new_allapot);
    int get_kor() const;
    void set_kor(int new_kor);
    void set_toltott(int new_toltott);

protected:

private:
    Pontok pontszam;
    int jatekkor;
    int jatekallapot;
    int toltott;
    int gyoztes;
    int kekosszesen;
    int zoldosszesen;
    Szinezett negyzet[15][15];
    //0-?res, 1-zold, 2-kek
};

#endif // JATEK_H
