#include "compat/ptr.h"
#include "decls/data/engine/audio.h"

struct Obj_24ace0 {
    int Do(int, int, int, int, int, int);
};
extern "C" hulk_intptr __cdecl GetThing(void*);
extern "C" int __cdecl FUN_0024ace0(int a, int b, int c, int d, int e, int f) {
    Obj_24ace0* p = (Obj_24ace0*)GetThing((void*)((hulk_intptr)DAT_004e5fa8));
    if (p)
        return p->Do(a, b, c, d, e, f);
    return 0;
}