#include "gen/hulkfight.h"

extern "C" void* FUN_00344e74(void*, int, void*, void*, int);
extern int g_params;
extern int g_scen;

struct Rec_1a4ba0 {
    char pad0[4];
    int type;
    char pad1[0x10];
    int a;
    int b;
};
struct Getter_1a4ba0 {
    Rec_1a4ba0* get();
};

bool hulkfight::scenario::Event_StringCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { void * p1 = (void *)__p0; void * p2 = (void *)__p1; void * p3 = (void *)__p2;

    Getter_1a4ba0* g = (Getter_1a4ba0*)FUN_00344e74(p2, 0, &g_params, &g_scen, 0);
    if (g) {
        Rec_1a4ba0* r = g->get();
        if (r->type == 0x1b && r->a == this->f_10 && r->b == this->f_14)
            return true;
    }
    return false;
}
