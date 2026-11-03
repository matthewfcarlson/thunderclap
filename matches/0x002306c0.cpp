#include "compat/ptr.h"
#include "gen/owners.h"
typedef unsigned int U_2306c0;
struct H {
    void run(owners::Obj_2306c0*, U_2306c0*);
};
void owners::Obj_2306c0::FUN_002306c0(hulk_intptr arg) {
    U_2306c0 temp[4];
    ((H*)((hulk_uintptr)arg))->run(this, temp);
    a = temp[0];
    b = temp[1];
    c = temp[2];
    d = temp[3];
}