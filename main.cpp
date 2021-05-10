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
//allapot: 0-menu, 1-jatek, 2-rules, 5-exit

int main()
{
    gout.open(1330,830);//jobb oldalt marad 500, 830-tol
    gout.load_font("LiberationSans-Regular.ttf", 20, true);
    gin.timer(400);
    int allapot=0;
    int kor=1;
    event evt;
    Rajzol felulet(kor);
    Jatek jatek(kor, allapot, felulet);

    while(gin >> evt && evt.keycode!=key_escape)
    {
        jatek.set_allapot(allapot);
        jatek.set_kor(kor);
        jatek.allapot_vizsg(jatek, felulet, evt);
        allapot=jatek.get_allapot();
        kor=jatek.get_kor();
        if(allapot==5)
        {
            break;
        }

        /*if(allapot==0)
        {
            //felulet.palya_rajz();
            felulet.clr_src();
            felulet.menu_rajz();
            if(evt.type == ev_mouse && evt.button==btn_left)
            {
                jatek.katt_vizsg(allapot, evt);
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
            }

        }
        else if(allapot==1)
        {

            felulet.clr_src();
            felulet.kor_rajz();
            felulet.palya_rajz();
            jatek.kor_vizsg(kor, evt, felulet, jatek); //ez a ketto hibas
            kor=jatek.get_kor();
            if(kor==1)
            {
                felulet.green_rajz(evt, felulet);
                kor=felulet.get_kor();
            }
            else if(kor==2)
            {
                felulet.blue_rajz(evt, felulet);
                kor=felulet.get_kor();
            }
        }
        else if(allapot==2)
        {
            felulet.clr_src();
            felulet.rules_rajz();
            //jatek.katt_vizsg(allapot, evt);
            if(evt.type == ev_mouse && evt.button==btn_left)
            {
                if(evt.pos_x >= 1046 && evt.pos_x <= 1100 && evt.pos_y >= 170 && evt.pos_y <= 190)
                {
                    allapot=0;//Menu
                }
            }

        }
        else if(allapot==5)
        {
            break;
        }
        gout << refresh;*/
    }
    return 0;
}
