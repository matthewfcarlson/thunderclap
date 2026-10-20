#include "compat/ptr.h"
struct Sub_221cd0 {
    char pad[0x10];
    void f(int);
};
struct C_221cd0 {
    char pad[0x40];
    Sub_221cd0 sub;
    int state;
    void* target();
};
void* C_221cd0::target() {
    if (state == 2) {
        sub.f((hulk_intptr)this);
        state = 0;
    }
    return (void*)&sub;
}