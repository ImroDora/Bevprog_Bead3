#include "Jatek.h"
#include "Rajzol.h"
#include "graphics.hpp"
#include <iostream>
#include <ostream>
#include <vector>

using namespace std;
using namespace genv;

Jatek::Jatek(int kor, int allapot, Rajzol felulet)
{
    set_allapot(allapot);
    set_kor(kor);

    toltott=0;
    jatekkor=0;
    jatekallapot=0;
    gyoztes=0;

    for(int i=0; i<15; i++)
    {
        for(int j=0; j<15; j++)
        {
            negyzet[i][j].x=10+i*54;
            negyzet[i][j].y=10+j*54;
            negyzet[i][j].zold=false;
            negyzet[i][j].kek=false;
        }
    }
}

Jatek::~Jatek()
{
    //dtor
}

void Jatek::allapot_vizsg(Jatek jatek, Rajzol felulet, event evt, int allapot, int kor)
{
        jatek.set_allapot(allapot);
        if(jatekallapot==0)
        {
            //felulet.palya_rajz();
            felulet.clr_src();
            felulet.menu_rajz();
            if(evt.type == ev_mouse && evt.button==btn_left)
            {
                if(evt.pos_x >= 1046 && evt.pos_x <= 1110 && evt.pos_y >= 60 && evt.pos_y <= 80)
                {
                    jatekallapot=1;//Start
                }
                else if(evt.pos_x >= 1046 && evt.pos_x <= 1110 && evt.pos_y >= 90 && evt.pos_y <= 110)
                {
                    jatekallapot=2;//Rules
                }
                else if(evt.pos_x >= 1030 && evt.pos_x <= 1130 && evt.pos_y >= 120 && evt.pos_y <= 140)
                {
                    jatekallapot=5;
                }
            }

        }
        else if(jatekallapot==1)
        {

            felulet.clr_src();
            felulet.palya_rajz();
            felulet.kor_rajz(kor);
            jatek.kor_vizsg(kor, evt, felulet, jatek);
            kor=jatek.get_kor();
        }
        else if(jatekallapot==2)
        {
            felulet.clr_src();
            felulet.rules_rajz();
            if(evt.type == ev_mouse && evt.button==btn_left)
            {
                if(evt.pos_x >= 1046 && evt.pos_x <= 1100 && evt.pos_y >= 170 && evt.pos_y <= 190)
                {
                    jatekallapot=0;//Menu
                }
            }

        }
        gout << refresh;
}

void Jatek::kor_vizsg(int kor, event evt, Rajzol felulet, Jatek jatek)
{
    //jatek.set_kor(kor); ez a jo
    jatekkor=kor;
    Point a(10,10);
    Size b(54,54);
    if(jatekkor==1)
    {
        if(evt.type==ev_mouse && evt.button==btn_left)
        {
            for(int i=0; i<15; i++) //oszlop vizsgalat
            {
                for(int j=0; j<15; j++) //sor
                {
                    if(evt.pos_x>=a.x+i*b.w && evt.pos_x<=a.x+(i+1)*b.w && evt.pos_y>=a.y+j*b.h && evt.pos_y<=a.y+(j+1)*b.h &&
                       !negyzet[i][j].zold && !negyzet[i][j].kek)
                    {

                        //felulet.kor_rajz(jatekkor);
                        felulet.green_rajz(evt, felulet, a, b, i, j);
                        negyzet[i][j].zold=true;
                        toltott++;
                        jatekkor=2;
                    }
                }
            }
        }
    }
    else if(jatekkor==2)
    {
        if(evt.type==ev_mouse && evt.button==btn_left)
        {
            for(int i=0; i<15; i++) //oszlop vizsgalat
            {
                for(int j=0; j<15; j++) //sor
                {
                    if(evt.pos_x>=a.x+i*b.w && evt.pos_x<=a.x+(i+1)*b.w && evt.pos_y>=a.y+j*b.h && evt.pos_y<=a.y+(j+1)*b.h &&
                        !negyzet[i][j].zold && !negyzet[i][j].kek)
                    {
                        //felulet.kor_rajz(jatekkor);
                        felulet.blue_rajz(evt, felulet, a, b, i, j);
                        negyzet[i][j].kek=true;
                        toltott++;
                        jatekkor=1;
                    }
                }
            }
        }
    }
}

void Jatek::gyozelem_vizsg()
{
    if(toltott==225)
        jatekallapot=3;
    //zold
    for(int i=0; i < 15; i++)
    {
        for(int j=0; j < 15; j++)
        {
            if(negyzet[i][j].zold)//gyoztes=1;
            {
                zoldosszesen=1;
                for(int k=1; k <= 4; k++)
                {
                    //jobbra
                    if(negyzet[i+k][j].zold)
                        zoldosszesen++;
                    if(zoldosszesen==5)
                        jatekallapot=4;
                        gyoztes=1;
                }
                zoldosszesen=1;
                for(int k=1; k <= 4; k++)
                {
                    //lefele
                    if(negyzet[i][j+k].zold)
                        zoldosszesen++;
                    if(zoldosszesen==5)
                        jatekallapot=4;
                        gyoztes=1;
                }
                zoldosszesen=1;
                for(int k=1; k <= 4; k++)
                {
                    //keresztbe jobbra
                    if(negyzet[i+k][j+k].zold)
                        zoldosszesen++;
                    if(zoldosszesen==5)
                        jatekallapot=4;
                        gyoztes=1;
                }
                zoldosszesen=1;
                for(int k=1; k <= 4; k++)
                {
                    //keresztbe balra
                    if(negyzet[i-k][j+k].zold)
                        zoldosszesen++;
                    if(zoldosszesen==5)
                        jatekallapot=4;
                        gyoztes=1;
                }
            }
            if(negyzet[i][j].kek)//gyoztes=2;
            {
                kekosszesen=1;
                for(int k=1; k <= 4; k++)
                {
                    //jobbra
                    if(negyzet[i+k][j].kek)
                        kekosszesen++;
                    if(kekosszesen==5)
                        jatekallapot=4;
                        gyoztes=2;
                }
                kekosszesen=1;
                for(int k=1; k <= 4; k++)
                {
                    //lefele
                    if(negyzet[i][j+k].zold)
                        kekosszesen++;
                    if(kekosszesen==5)
                        jatekallapot=4;
                        gyoztes=2;
                }
                kekosszesen=1;
                for(int k=1; k <= 4; k++)
                {
                    //keresztbe jobbra
                    if(negyzet[i+k][j+k].zold)
                        kekosszesen++;
                    if(kekosszesen==5)
                        jatekallapot=4;
                        gyoztes=2;
                }
                kekosszesen=1;
                for(int k=1; k <= 4; k++)
                {
                    //keresztbe balra
                    if(negyzet[i-k][j+k].zold)
                        kekosszesen++;
                    if(kekosszesen==5)
                        jatekallapot=4;
                        gyoztes=2;
                }
            }
        }
    }
}

void Jatek::gyozelem(Rajzol felulet)
{
    if(gyoztes==1)
        felulet.zoldgyozelem_rajz();
    else if(gyoztes==2)
        felulet.kekgyozelem_rajz();
}
//megmarad a jatekos allapot, vesztes tudja kezdeni - direkt

void Jatek::helyek_null()
{
    for(int i=0; i<15; i++)
    {
        for(int j=0; j<15; j++)
        {
            negyzet[i][j].zold=false;
            negyzet[i][j].kek=false;
        }
    }
}




Pontok Jatek::get_pontszam() const
{
    return pontszam;
}
void Jatek::set_pontszam(Pontok new_pontszam)
{
    pontszam = new_pontszam;
}
int Jatek::get_allapot() const
{
    return jatekallapot;
}
void Jatek::set_allapot(int new_allapot)
{
    jatekallapot=new_allapot;
}
int Jatek::get_kor() const
{
    return jatekkor;
}
void Jatek::set_kor(int new_kor)
{
    jatekkor=new_kor;
}

//green(170, 255, 209)
//blue(167, 199, 255)
