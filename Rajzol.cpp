#include "Rajzol.h"
#include "graphics.hpp"

using namespace std;
using namespace genv;

Rajzol::Rajzol(int kor_szam)
{
    set_kor(kor_szam);
}

Rajzol::~Rajzol()
{
    //dtor
}

int Rajzol::get_kor() const
{
    return korszam;
}
void Rajzol::set_kor(int new_kor)
{
    korszam = new_kor;
}

void Rajzol::clr_src()
{
    gout << move_to(830,0) //clear resz(felso)
         << color(0, 0, 0)
         << box(500, 830);
}

void Rajzol::menu_rajz()
{
    gout << color(255, 255, 255) //menurajz
         << move_to(1050, 30)
         << text("MENU")
         << move_to(1050, 51)
         << line(60,0)
         << move_to(1046, 60)
         << text("START")
         << move_to(1046, 90)
         << text("RULES")
         << move_to(1030, 120)
         << text("EXIT / ESC");
}

void Rajzol::rules_rajz()
{
    gout << color(255, 255, 255) //menurajz
         << move_to(1050, 30)
         << text("RULES")
         << move_to(1050,51)
         << line(67,0)
         << move_to(980, 60)
         << text("RAKJ LE EGY SZINBOL")
         << move_to(980, 90)
         << text(" 5-OT EGYMAS MELLE")
         << move_to(930, 120)
         << text("FERDE, VIZSZINT, FUGGOLEGES")
         << move_to(1046, 170)
         << text("BACK");
}

void Rajzol::palya_rajz()
{
    //Palya alapkör
    gout << color(199, 0, 57)
         << move_to(0, 0)
         << box(830, 10)
         << move_to(820, 0)
         << box(10, 830)
         << move_to(830, 820)
         << box(-830, 10)
         << move_to(0, 830)
         << box(10, -830);
    //Palya kockazas - 54 szélesség
    for(int i=1; i<=14; i++)
    {
        gout << move_to(i*54+10, 10)//(10,0)-tól kezdodik a palya
             << line(0,810);

    };
    for(int i=1; i<=14; i++)
    {
        gout << move_to(10, i*54+10)//(10,110)-tól kezdodik a palya
             << line(810,0);

    };
}

void Rajzol::kor_rajz()
{
    if(korszam==1)//zold
    {
        gout << color(170, 255, 209)
             << move_to(1020, 60)
             << text("GREEN'S TURN");
    }
    else//kek
    {
        gout << color(167, 199, 255)
             << move_to(1030, 60)
             << text("BLUE'S TURN");
    }

}

void Rajzol::green_rajz(event evt, Rajzol felulet)
{
    if(evt.type==ev_mouse && evt.button==btn_left)
    {
        for(int i=0; i<15; i++) //oszlop vizsgalat
        {
            for(int j=0; j<15; j++) //sor
            {
                if(evt.pos_x>=10+i*54 && evt.pos_x<=10+(i+1)*54 && evt.pos_y>=10+j*54 && evt.pos_y<=10+(j+1)*54)
                {
                    gout << color(170, 255, 209)
                         << move_to(i*54+10,j*54+10)
                         << box(54,54);
                    korszam=2;
                    felulet.set_kor(korszam);
                }
            }
        }
    }
}

void Rajzol::blue_rajz(event evt, Rajzol felulet)
{
    Point a(10,10);
    Size b(54,54);
    if(evt.type==ev_mouse && evt.button==btn_left)
    {
        for(int i=0; i<15; i++) //oszlop vizsgalat
        {
            for(int j=0; j<15; j++) //sor
            {
                if(evt.pos_x>=a.x+i*b.w && evt.pos_x<=a.x+(i+1)*b.w && evt.pos_y>=a.y+j*b.h && evt.pos_y<=a.y+(j+1)*b.h)
                {
                    gout << color(167, 199, 255)
                         << move_to(i*b.w+a.x,j*b.h+a.y)
                         << box(b.w,b.h);
                    korszam=1;
                    felulet.set_kor(korszam);
                }
            }
        }
    }
}
