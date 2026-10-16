#include "gen/pure3d.h"

typedef unsigned int u32_2c0070;
void thunk_FUN_00267090(void*);
void* FUN_0008d6d0(u32_2c0070);

void pure3d::Image32::vfunc_5(int w, int h) {
    this->f_10 = w;
    this->f_14 = h;
    thunk_FUN_00267090((*(void * *)&this->f_24));
    (*(void * *)&this->f_24) = FUN_0008d6d0(this->f_14 * this->f_10 * 4);
}
