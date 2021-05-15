#ifndef RUNABLE_H
#define RUNABLE_H
#include "graphics.hpp"
#include "Widget.h"
#include "Rajzol.h"

using namespace std;
using namespace genv;

class Runable
{
    public:
        Runable(int allapot, event evt);
        virtual ~Runable();
        int get_allapot() const;
        void set_allapot(int new_allapot);

        void run();
        void menu_choice(int allapot, event evt);

    protected:

    private:
        int allapot;
        int kor;
};

#endif // RUNABLE_H
