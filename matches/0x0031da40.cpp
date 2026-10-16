#include "gen/pure3d.h"

typedef unsigned char u8;

void pure3d::pddiBaseContext::vfunc_38(int i, int v) {
    if (i < 8) {
        *((u8*)(*(void * *)&this->f_50) + (i + 1) * 0x7c) = (u8)v;
        vfunc_110(i, 0);
    }
}
