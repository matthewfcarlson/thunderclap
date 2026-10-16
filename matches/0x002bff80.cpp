#include "gen/pure3d.h"

typedef unsigned char u8;
extern "C" void* memset(void*, int, unsigned int);

void pure3d::Image8::vfunc_11(unsigned int __p0) { int value = (int)__p0;

    memset((*(u8 * *)&this->f_24), value, this->f_10 * this->f_14);
}
