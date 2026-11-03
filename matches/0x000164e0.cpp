#include "gen/global.h"
#include "gen/owners.h"

struct Sub_164e0 {
    int query(int);
};
struct Obj_164e0 {
    char pad[0x40];
    int value;
    char pad2[0xa8];
    Sub_164e0* sub;
    void mutate(int);
    int finish(int);
};
struct A_164e0 {
    void* next();
};
struct B_164e0 {
    void* next();
};

bool CSmartPropEventAction::vfunc_6(int x) {
    A_164e0* a = (A_164e0*)(*(void * *)&this->f_1c);
    void* p = a->next();
    B_164e0* b = (B_164e0*)p;
    p = b->next();
    Obj_164e0* o = ((Obj_164e0 *)((owners::C_35ef0 *)(((B_164e0*)p)))->FUN_00035ef0((hulk_intptr)((*(void * *)&this->f_24))));
    if (o) {
        int old = o->value;
        o->mutate(this->f_20);
        int cur = o->value;
        if (cur != old || this->f_20 == 3) {
            int n = o->sub->query(cur);
            if (n > 0)
                o->finish(n);
        }
    }
    return false;
}
