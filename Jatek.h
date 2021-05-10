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

    //oid helyek_nulla();
    void allapot_vizsg(Jatek jatek, Rajzol felulet, event evt);
    //void katt_vizsg(int allapot, event evt);
    //void kor_vizsg(int kor, event evt, Rajzol felulet, Jatek jatek);

    Pontok get_pontszam() const;
    void set_pontszam(Pontok new_pontszam);

    int get_allapot() const;
    void set_allapot(int new_allapot);
    int get_kor() const;
    void set_kor(int new_kor);

protected:

private:
    Pontok pontszam;
    int jatekkor;
    int jatekallapot;
    Szinezett sorok;
    vector<Szinezett> helyek;
    //0-üres, 1-zold, 2-kek
};

#endif // JATEK_H
