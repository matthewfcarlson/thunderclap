#include "gen/pure3d.h"

typedef unsigned int u32_327200;
extern void FUN_0031c230(int);

int pure3d::d3dPrimBuffer::vfunc_7() {
    u32_327200 result = *(u32_327200*)((char*)(*(void * *)&this->f_2c) + 4);
    FUN_0031c230(0);
    this->f_35 = 1;
    return (int)(result);
}
