#include "decls/data/engine/core.h"
// data: g_value_334010 = DAT_004cdbb0

#include "compat/ptr.h"
// movie::PlayerBink on the heap `heap` (0x00333f10 constructs it and returns it)
extern "C" void* __cdecl FUN_00266e00(int, hulk_intptr);
struct Obj_334010 {
    void* FUN_00333f10();
};
extern "C" void* __cdecl FUN_00334010(int heap) {
    HULK_SIZE32(MoviePlayerBink, 0x1dc);
    DAT_004cdbb0 = heap;
    Obj_334010* q = (Obj_334010*)FUN_00266e00(heap, (hulk_intptr)sizeof(MoviePlayerBink));
    if (q)
        return q->FUN_00333f10();
    return 0;
}
