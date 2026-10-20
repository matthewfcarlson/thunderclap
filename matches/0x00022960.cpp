#include "compat/ptr.h"
extern "C" char DAT_003f3e88[];
struct Caster_22960 {
    int* v;
};
struct Host_22960 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual int d(Caster_22960*, int, int);
    int run(int, int);
};
int Host_22960::run(int x, int y) {
    Caster_22960 c;
    c.v = (int*)((hulk_intptr)DAT_003f3e88);
    return d(&c, x, y);
}