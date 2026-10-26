#include "decls/data/game/global.h"
// data: zero = DAT_003f335c

extern "C" void _ReadWriteBarrier();
struct Vec {
    void Init();
    void Set(const float*);
};
struct Obj {
    int a, b, c, d, e, f;
    Vec v;
    Obj();
};
Obj::Obj() {
    v.Init();
    v.Set(&DAT_003f335c);
    a = 0;
    d = 0;
    c = 0;
    b = 0;
    _ReadWriteBarrier();
    e = 0;
    v.Set(&DAT_003f335c);
}