#include "gen/owners.h"
extern char DAT_0049dba4[], DAT_0049f4f0[], DAT_0049f454[];
extern "C" int __cdecl FUN_00344e74(int, int, char*, char*, int);
int owners::ThisWrap_000e7560::FUN_000e7560(int x) {
    return FUN_00344e74(FUN_00344e74(this->helper(x), 0, DAT_0049dba4, DAT_0049f4f0, 0), 0, DAT_0049f4f0, DAT_0049f454, 0);
}