#include "compat/ptr.h"
extern "C" char DAT_003f6098[];
void thunk(void*);
struct CSPListener_1db200 {
    int pad;
    void* vf;
    CSPListener_1db200* f(unsigned char flags);
};
CSPListener_1db200* CSPListener_1db200::f(unsigned char flags) {
    CSPListener_1db200* self = this;
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