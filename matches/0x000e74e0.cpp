#include "gen/owners.h"
extern int __cdecl FUN_00344e74(int, int, void*, void*, int);
extern char DAT_0049dba4, DAT_0049f4f0, DAT_0049f470;
int owners::ThisWrap_000e74e0::FUN_000e74e0(int x) {
    return FUN_00344e74(FUN_00344e74(this->Inner(x), 0, &DAT_0049dba4, &DAT_0049f4f0, 0), 0, &DAT_0049f4f0, &DAT_0049f470, 0);
}