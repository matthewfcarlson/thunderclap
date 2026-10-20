#include "compat/ptr.h"
#include "decls/data/engine/audio.h"

struct Obj_24ae50 {
    int x;
    void Helper();
    Obj_24ae50* Bar(unsigned char flag);
};
void __cdecl FUN_00247550(void*, Obj_24ae50*);
Obj_24ae50* Obj_24ae50::Bar(unsigned char flag) {
    Helper();
    if (flag & 1)
        FUN_00247550((void*)((hulk_intptr)DAT_004e5fa8), this);
    return this;
}
