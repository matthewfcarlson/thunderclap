#include "gen/owners.h"
extern void __cdecl Init(owners::Obj_fefc0*, int*);
hulk_intptr owners::Obj_fefc0::FUN_000fefc0() {
    if (value == 0)
        Init(this, &value);
    return value;
}