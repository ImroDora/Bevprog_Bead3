#include "Runable.h"
#include "graphics.hpp"
#include <string>
#include <vector>

using namespace std;
using namespace genv;

Runable::Runable(int allapot, event evt)
{
    set_allapot(allapot);
}

Runable::~Runable()
{
    //dtor
}

int Runable::get_allapot() const
{
    return allapot;
}
void Runable::set_allapot(int new_allapot)
{
    allapot=new_allapot;
}

void Runable::menu_choice(int allapot, event evt)
{
    if(allapot==0)
    {
        if(evt.type == ev_mouse && evt.button==btn_left)
        {
            if(allapot==0)
            {
                if(evt.pos_x >= 1046 && evt.pos_x <= 1110 && evt.pos_y >= 60 && evt.pos_y <= 80)
                {
                    set_allapot(1);//Start
                }
                else if(evt.pos_x >= 1046 && evt.pos_x <= 1110 && evt.pos_y >= 90 && evt.pos_y <= 110)
                {
                    set_allapot(2);//Rules
                }
                else if(evt.pos_x >= 1030 && evt.pos_x <= 1130 && evt.pos_y >= 120 && evt.pos_y <= 140)
                {
                    set_allapot(5);//Exit
                }
            }
        }

    }
    else if(allapot==2)
    {
        if(evt.type == ev_mouse && evt.button==btn_left)
        {
            if(evt.pos_x >= 1046 && evt.pos_x <= 1100 && evt.pos_y >= 170 && evt.pos_y <= 190)
            {
                set_allapot(0);//Menu
            }
        }

    }
}

void Runable::run()
{
    gout.open(1330,830);//jobb oldalt marad 500, 830-tol
    gout.load_font("LiberationSans-Regular.ttf", 20, true);
    gin.timer(400);
    Rajzol felulet(kor);
    event evt;
    Runable master(allapot, evt);
    allapot=0;
    kor=1;

    while(gin >> evt && evt.keycode!=key_escape)
    {
        if(allapot==0)
        {
            felulet.clr_src();
            felulet.menu_rajz();
            master.menu_choice(allapot, evt);
        }
    }
}
