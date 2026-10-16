#include "gen/pure3d.h"

typedef unsigned char u8;
extern "C" void* memcpy(void*, const void*, unsigned int);

void pure3d::Image8::vfunc_6(int width, int height, void* __p2) { const void * src = (const void *)__p2;

    vfunc_5(width, height);
    memcpy((*(u8 * *)&this->f_24), src, width * height);
}
