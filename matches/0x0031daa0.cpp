#include "gen/pure3d.h"

void pure3d::pddiBaseContext::vfunc_40(int i, int v) {
    if (i < 8) {
        ((int*)((char*)(*(void * *)&this->f_50) + i * 0x7c + 0x74))[0] = v;
        vfunc_110(i, 0);
    }
}
