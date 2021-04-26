#include "graphics.hpp"
#include "Widget.h"
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>
using namespace genv;
using namespace std;


int main()
{
    gout.open(800,800);
    event evt;
    while(gin >> evt && evt.keycode!=key_escape)
        {
            gout << move_to(0,0);
        }
    return 0;
}
