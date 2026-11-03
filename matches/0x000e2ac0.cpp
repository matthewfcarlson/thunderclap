#include "gen/owners.h"
void ReleaseThing(int);
void owners::Obj_e2ac0::FUN_000e2ac0(hulk_intptr value) {
    int old = field;
    if (old != 0) {
        ReleaseThing(old);
        field = 0;
        field = ((int)value);
    } else {
        field = ((int)value);
    }
}