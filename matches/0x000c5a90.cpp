#include "gen/owners.h"
typedef unsigned int U_c5a90;
struct Triple_c5a90 {
    U_c5a90 x, y, z;
};
struct Helper_c5a90 {
    U_c5a90 B(U_c5a90, U_c5a90);
};
struct Obj_c5a90 {
    Helper_c5a90* h;
    U_c5a90 pad;
    U_c5a90 c;
    U_c5a90 d;
    Triple_c5a90* Go(Triple_c5a90* out);
};
Triple_c5a90* Obj_c5a90::Go(Triple_c5a90* out) {
    Triple_c5a90 t;
    ((owners::C_284820 *)h)->FUN_00284820((hulk_intptr)0);
    U_c5a90 r = h->B(c, d);
    ((owners::Obj_2848b0 *)h)->FUN_002848b0((hulk_intptr)r, 0, (int *)(Triple_c5a90 *)(&t));
    *out = t;
    return out;
}
