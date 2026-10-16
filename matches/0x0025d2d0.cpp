#include "decls/data/engine/audio.h"

struct Obj_25d2d0 {
    char pad[0x1c];
    int member;
    Obj_25d2d0* target(int flags);
};
struct Helper_25d2d0 {
    void call();
};
extern void __cdecl FUN_00247550(void*, Obj_25d2d0*);
Obj_25d2d0* Obj_25d2d0::target(int flags) {
    ((Helper_25d2d0*)&member)->call();
    if (flags & 1)
        FUN_00247550((void*)((int)DAT_004e7898), this);
    return this;
}