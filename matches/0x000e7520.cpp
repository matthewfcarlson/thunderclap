#include "compat/ptr.h"
struct ThisWrap_000e7520 {
    int FUN_000e7260(int);
    hulk_intptr FUN_000e7520(int x);
};
extern hulk_intptr __cdecl FUN_00344e74(hulk_intptr, int, hulk_intptr, hulk_intptr, int);
extern int a, b, c;
hulk_intptr ThisWrap_000e7520::FUN_000e7520(int x) {
    return FUN_00344e74(FUN_00344e74(this->FUN_000e7260(x), 0, (hulk_intptr)&a, (hulk_intptr)&b, 0), 0, (hulk_intptr)&b, (hulk_intptr)&c, 0);
}