#include "gen/global.h"

struct H1 {
    void* f();
};
struct H2_147d0 {
    void* f();
};
struct H3_147d0 {
    char p[0x64];
    void* q;
};
struct H4 {
    char p[0x1c];
    void* z;
};
struct Helper_147d0 {
    char p[0x1c];
    void f(void*, void*);
};
struct V {
    int a, b, c;
};
struct B_147d0 {
    char p[0x20];
    V v;
};

bool COpportunityBallAction::vfunc_6(int arg) {
    void* a = ((H1*)(*(void * *)&this->f_1c))->f();
    a = ((H2_147d0*)a)->f();
    V local = ((B_147d0*)(*(void * *)&this->f_20))->v;
    void* x = ((H3_147d0*)a)->q;
    void* base = ((H4*)x)->z;
    ((Helper_147d0*)((char*)base + (this->f_24 << 6)))->f(&local, &this->f_28);
    return true;
}
