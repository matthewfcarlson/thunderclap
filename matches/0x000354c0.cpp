#include "compat/ptr.h"
#include "decls/data/game/global.h"
// data: gZero_354c0 = DAT_003f32e0

// The original tail-jumps to FUN_002220d0: its st0 (the unrounded heading) is this function's result, so the
// clang build must not round it to float here: the definition returns hulk_freg (callees stay declared float).
struct Inner_354c0 {
    char pad[0x10];
    void* Get();
    float Calc();   // returns st0; the Wine build reads it unrounded (clang_probe retfix)
};
struct Owner_354c0 {
    char pad[0x10];
    Inner_354c0* m;
    hulk_freg f();
};
hulk_freg Owner_354c0::f() {
    Inner_354c0* p = m;
    void* q = p->Get();
    if (!q)
        return DAT_003f32e0;
    return ((Inner_354c0*)((char*)q + 0x10))->Calc();
}
