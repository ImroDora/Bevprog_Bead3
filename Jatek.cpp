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
}

Jatek::~Jatek()
{
    //dtor
}

void Jatek::allapot_vizsg(Jatek jatek, Rajzol felulet, event evt)
{

    if(jatekallapot==0)
        {
            //felulet.palya_rajz();
            felulet.clr_src();
            felulet.menu_rajz();
            if(evt.type == ev_mouse && evt.button==btn_left)
            {
                if(jatekallapot==0)
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

        }
        else if(jatekallapot==1)
        {

            felulet.clr_src();
            felulet.kor_rajz();
            felulet.palya_rajz();
            /*jatek.kor_vizsg(kor, evt, felulet, jatek); //ez a ketto hibas
            kor=jatek.get_kor();*/
            if(jatekkor==1)
            {
                felulet.green_rajz(evt, felulet);
                jatekkor=felulet.get_kor();
            }
            else if(jatekkor==2)
            {
                felulet.blue_rajz(evt, felulet);
                jatekkor=felulet.get_kor();
            }
        }
        else if(jatekallapot==2)
        {
            felulet.clr_src();
            felulet.rules_rajz();
            //jatek.katt_vizsg(jatekallapot, evt);
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

/*void Jatek::katt_vizsg(int allapot, event evt)
{
    if(evt.type == ev_mouse && evt.button==btn_left)
    {
        if(allapot==0)
        {
            if(evt.pos_x >= 1046 && evt.pos_x <= 1110 && evt.pos_y >= 60 && evt.pos_y <= 80)
            {
                allapot=1;//Start
            }
            else if(evt.pos_x >= 1046 && evt.pos_x <= 1110 && evt.pos_y >= 90 && evt.pos_y <= 110)
            {
                allapot=2;//Rules
            }
            else if(evt.pos_x >= 1030 && evt.pos_x <= 1130 && evt.pos_y >= 120 && evt.pos_y <= 140)
            {
                allapot=5;
            }
        }
        else if(allapot==2)
        {
            if(evt.pos_x >= 1046 && evt.pos_x <= 1100 && evt.pos_y >= 170 && evt.pos_y <= 190)
            {
                allapot=0;//Menu
            }
        }
    }
}*/

/*void Jatek::kor_vizsg(int kor, event evt, Rajzol felulet, Jatek jatek)
{
    jatek.set_kor(kor);
    for(int i=0;i<225;i++)
    {
        if(jatekkor==1)
        {
            felulet.green_rajz(evt, felulet);
            jatek.set_kor(felulet.get_kor());
        }
        else if(jatekkor==2)
        {
            felulet.blue_rajz(evt, felulet);
            jatek.set_kor(felulet.get_kor());
        }
    }
}*/

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
