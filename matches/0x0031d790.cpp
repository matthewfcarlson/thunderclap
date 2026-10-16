#include "gen/pure3d.h"

void pure3d::pddiBaseContext::vfunc_28(unsigned int a, unsigned int b, unsigned int c, unsigned int d) {
    unsigned* p = (unsigned*)((char*)(*(unsigned int * *)&this->f_48) + 0x24);
    p[0] = a;
    p[1] = b;
    p[2] = c;
    p[3] = d;
    vfunc_109();
}
