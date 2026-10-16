#include "gen/global.h"

struct Obj_4a2d0 {
    char pad[0x330];
    int a;
    int b;
    int c;
};
struct Helper_4a2d0 {
    Obj_4a2d0* First();
};
struct ObjHelper_4a2d0 {
    Obj_4a2d0* Second();
};

int CGrappleMotionStateCondition::vfunc_8(int p) {
    if (!p)
        return 0;
    Helper_4a2d0* h = (Helper_4a2d0*)p;
    Obj_4a2d0* x = h->First();
    x = ((ObjHelper_4a2d0*)x)->Second();
    if (x->b)
        return x->b;
    if (x->a)
        return x->a;
    return x->c;
}
