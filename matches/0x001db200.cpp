#include "compat/ptr.h"
extern "C" char DAT_003f6098[];
void thunk(void*);
struct Obj_1db200 {
    int pad;
    void* vf;
    Obj_1db200* f(unsigned char flags);
};
Obj_1db200* Obj_1db200::f(unsigned char flags) {
    Obj_1db200* self = this;
    volatile void** p;
    if (self)
        p = (volatile void**)((char*)self + 4);
    else
        p = 0;
    *p = (void*)((hulk_intptr)DAT_003f6098);
    if (flags & 1)
        thunk(self);
    return self;
}