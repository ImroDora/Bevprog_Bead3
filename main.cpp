#include "graphics.hpp"
#include "Widget.h"
#include "Rajzol.h"
#include "Jatek.h"
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <ostream>
#include <fstream>
using namespace genv;
using namespace std;

//green(170, 255, 209)
//blue(167, 199, 255)
//red(199, 0, 57)
//allapot: 0-menu, 1-jatek, 2-rules, 3-tele palya, 4-gyozelem, 6-exit

int main()
{
    gout.open(1330,830);//jobb oldalt marad 500, 830-tol
    gout.load_font("LiberationSans-Regular.ttf", 20, true);
    gin.timer(400);
    int allapot=0;
    int kor=1;
    event evt;
    Rajzol felulet;
    Jatek jatek(kor, allapot, felulet);

    while(gin >> evt && evt.keycode!=key_escape)
    {
        /*jatek.allapot_vizsg(jatek, felulet, evt, allapot, kor);
        allapot=jatek.get_allapot();
        if(allapot==5)
        {
            break;
        }*/
        if(allapot==0)
        {
            felulet.full_clr();
            jatek.set_toltott(0);
            felulet.clr_src();
            felulet.menu_rajz();
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
                        allapot=6;
                    }
                }
            }

        }
        else if(allapot==1)
        {

            jatek.set_allapot(allapot);
            felulet.clr_src();
            felulet.palya_rajz();
            felulet.kor_rajz(kor);
            jatek.kor_vizsg(kor, evt, felulet, jatek);
            jatek.gyozelem_vizsg();
            allapot=jatek.get_allapot();
            kor=jatek.get_kor();
        }
        else if(allapot==2)
        {
            felulet.clr_src();
            felulet.rules_rajz();
            if(evt.type == ev_mouse && evt.button==btn_left)
            {
                if(evt.pos_x >= 1046 && evt.pos_x <= 1100 && evt.pos_y >= 170 && evt.pos_y <= 190)
                {
                    allapot=0;//Menu
                }
            }

        }
        else if(allapot==3)
        {
            felulet.telepalya_rajz();
            if(evt.type == ev_mouse && evt.button==btn_left)
            {
                if(evt.pos_x >= 640 && evt.pos_x <= 700 && evt.pos_y >= 520 && evt.pos_y <= 540)
                {
                    allapot=0;//Menu
                }
            }
            jatek.helyek_null();
        }
        else if(allapot==4)
        {
            jatek.gyozelem(felulet);
            if(evt.type == ev_mouse && evt.button==btn_left)
            {
                if(evt.pos_x >= 640 && evt.pos_x <= 700 && evt.pos_y >= 520 && evt.pos_y <= 540)
                {
                    allapot=0;//Menu
                }
            }
            jatek.helyek_null();
        }
        else if(allapot==6)
        {
            break;
        }
        gout << refresh;
    }
    return 0;
}
