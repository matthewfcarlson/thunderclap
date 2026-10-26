#include "decls/data/game/global.h"

struct F_1b42b0 {
    unsigned lo, hi;
};
inline F_1b42b0 Or(const F_1b42b0& a, const F_1b42b0& b) {
    F_1b42b0 r;
    r.lo = a.lo | b.lo;
    r.hi = a.hi | b.hi;
    return r;
}
struct Inner_1b42b0 {
    char pad[0x58];
    F_1b42b0 a, b;
};
struct Obj_1b42b0 {
    char pad[0x74];
    Inner_1b42b0* in;
};
struct Mgr_1b42b0 {
    void Apply(Inner_1b42b0*);
};
struct Foo_1b42b0 {
    char pad[8];
    Mgr_1b42b0* mgr;
    bool Fn(Obj_1b42b0* o);
};
bool Foo_1b42b0::Fn(Obj_1b42b0* o) {
    if (!o)
        return false;
    Inner_1b42b0* i = o->in;
    if (!i)
        return false;
    i->a = (*(F_1b42b0*)&DAT_004c3a10);
    i->b = Or((*(F_1b42b0*)&DAT_004c3a20), Or((*(F_1b42b0*)&DAT_004c3a18), Or((*(F_1b42b0*)&DAT_004c39f0), (*(F_1b42b0*)&DAT_004c39e8))));
    mgr->Apply(i);
    return true;
}
