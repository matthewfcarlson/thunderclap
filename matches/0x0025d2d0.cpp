#include "compat/ptr.h"
#include "decls/data/engine/audio.h"
#include "gen/owners.h"

struct Obj_25d2d0 {
    char pad[0x1c];
    int member;
    Obj_25d2d0* target(int flags);
};
struct Helper_25d2d0 {
};
extern void __cdecl FUN_00247550(void*, Obj_25d2d0*);
Obj_25d2d0* Obj_25d2d0::target(int flags) {
    ((owners::Str_240060 *)(((Helper_25d2d0*)&member)))->FUN_00240060();
    if (flags & 1)
        FUN_00247550((void*)((hulk_intptr)DAT_004e7898), this);
    return this;
}