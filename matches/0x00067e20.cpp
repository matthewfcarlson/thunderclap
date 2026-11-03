#include "decls/data/game/global.h"
// data: zero = DAT_003f335c
#include "gen/owners.h"

extern "C" void _ReadWriteBarrier();
struct Vec {
    void Init();
};
struct Obj {
    int a, b, c, d, e, f;
    Vec v;
    Obj();
};
Obj::Obj() {
    v.Init();
    ((owners::Target_27b040 *)&v)->FUN_0027b040((hulk_uintptr)(&DAT_003f335c));
    a = 0;
    d = 0;
    c = 0;
    b = 0;
    _ReadWriteBarrier();
    e = 0;
    ((owners::Target_27b040 *)&v)->FUN_0027b040((hulk_uintptr)(&DAT_003f335c));
}