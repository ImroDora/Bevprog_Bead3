#include "Rajzol.h"
#include "graphics.hpp"
#include <iostream>
#include <sstream>

using namespace std;
using namespace genv;

Rajzol::Rajzol()
{

}

Rajzol::~Rajzol()
{
    //dtor
}

void Rajzol::full_clr()
{
    gout << move_to(0,0)
         << color(0, 0, 0)
         << box(1330, 830);
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

void Rajzol::kor_rajz(int korszam)
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

void Rajzol::green_rajz(event evt, Rajzol felulet, Point a, Size b, int i, int j)
{
    gout << color(170, 255, 209)
         << move_to(i*b.w+a.x,j*b.h+a.y)
         << box(b.w,b.h);
}

void Rajzol::blue_rajz(event evt, Rajzol felulet, Point a, Size b, int i, int j)
{
    gout << color(167, 199, 255)
         << move_to(i*b.w+a.x,j*b.h+a.y)
         << box(b.w,b.h);
}

void Rajzol::telepalya_rajz()
{
    gout << move_to(415, 265)
         << color(0, 0, 0)
         << box(500, 300)
         << move_to(415, 265)
         << color(255, 255, 255)
         << box(500, 10)
         << box(-10, 291)
         << box(-491, -10)
         << box(10, -290)
         << move_to(570, 375)
         << color(255, 0, 0)
         << text("THE BOARD IS FULL")
         << move_to(615, 405)
         << text("YOU LOST!")
         << move_to(640, 520)
         << text("RETRY");

}

void Rajzol::zoldgyozelem_rajz()
{
    gout << move_to(415, 265)
         << color(0, 0, 0)
         << box(500, 300)
         << move_to(415, 265)
         << color(255, 255, 255)
         << box(500, 10)
         << box(-10, 291)
         << box(-491, -10)
         << box(10, -290)
         << color(0, 255, 0)
         << move_to(610, 400)
         << text("GREEN WON!")
         << move_to(640, 520)
         << text("RETRY");
}

void Rajzol::kekgyozelem_rajz()
{
    gout << move_to(415, 265)
         << color(0, 0, 0)
         << box(500, 300)
         << move_to(415, 265)
         << color(255, 255, 255)
         << box(500, 10)
         << box(-10, 291)
         << box(-491, -10)
         << box(10, -290)
         << color(0, 255, 0)
         << move_to(615, 400)
         << text("BLUE WON!")
         << move_to(640, 520)
         << text("RETRY");
}
