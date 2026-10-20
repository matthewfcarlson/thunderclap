#include "compat/ptr.h"
extern "C" char DAT_004272b8[];
struct Sub_2235f0 {
    char pad[0x54];
    void init();
};
struct Puppet {
    void* vt;
    char pad[0xc];
    Sub_2235f0 sub;
    int a, b;
    void baseInit();
    void finish(int);
    Puppet* ctor(int arg);
};
Puppet* Puppet::ctor(int arg) {
    baseInit();
    vt = (void*)((hulk_intptr)DAT_004272b8);
    sub.init();
    a = 0;
    b = 0;
    finish(arg);
    return this;
}
