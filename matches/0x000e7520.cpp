#include "compat/ptr.h"
struct ThisWrap_000e7520 {
    int FUN_000e7260(int);
    hulk_intptr FUN_000e7520(int x);
};
extern hulk_intptr __cdecl FUN_00344e74(hulk_intptr, int, hulk_intptr, hulk_intptr, int);
extern int DAT_0049dba4, DAT_0049f4f0, DAT_004a1274;
hulk_intptr ThisWrap_000e7520::FUN_000e7520(int x) {
    return FUN_00344e74(FUN_00344e74(this->FUN_000e7260(x), 0, (hulk_intptr)&DAT_0049dba4, (hulk_intptr)&DAT_0049f4f0, 0), 0, (hulk_intptr)&DAT_0049f4f0, (hulk_intptr)&DAT_004a1274, 0);
}