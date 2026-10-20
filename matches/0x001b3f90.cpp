#include "compat/ptr.h"
extern int g_4c3880;
extern void* g_554c10;
struct Arg_1b3f90 {
    char p[0xc];
    int a;
    char q[0x14];
    int b;
};
struct Obj_1b3f90 {
    char p[0x4f0];
    hulk_intptr a, b, c;
    void target(Arg_1b3f90*);
};
struct Callee_1b3f90 {
    void call(int);
};
void Obj_1b3f90::target(Arg_1b3f90* arg) {
    a = arg->a;
    int t = arg->b;
    c = (hulk_intptr)arg;
    int g = g_4c3880;
    b = t;
    ((Callee_1b3f90*)g_554c10)->call(g);
}
