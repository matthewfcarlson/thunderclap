#include "gen/global.h"
struct Val_1d73f0 {
    char pad[0x18];
    float value;
};
struct Global_1d73f0 {
    char pad[0x24];
    Val_1d73f0* p;
};
extern Global_1d73f0* g_1d73f0;
class Helper_1d73f0 {
  public:
    int get();
};
class Other_1d73f0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3a();
    virtual int f4();
};
struct CSPHulkPropInstance_nv_1d73f0 {
    int run(int);
};
class Self_1d73f0 {
  public:
    char p0[0x40];
    int arg;
    char p1[0xa0 - 0x44];
    Helper_1d73f0* a;
    char p2[0xec - 0xa4];
    CSPHulkPropInstance* d;
    char p3[0x11c - 0xf0];
    Other_1d73f0* b;
};
int __fastcall target(Self_1d73f0* s) {
    float limit = g_1d73f0->p->value;
    int r;
    if (s->a)
        r = s->a->get() + 0x30;
    else
        r = ((Other_1d73f0*)s->b)->f4();
    if (*(float*)(r + 4) < limit)
        return -10;
    int v = s->arg;
    CSPHulkPropInstance* d = s->d;
    return ((CSPHulkPropInstance_nv_1d73f0*)(d))->run(v);
}
