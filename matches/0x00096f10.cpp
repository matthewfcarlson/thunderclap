#include "decls/data/game/hulkfight.h"
// data: buf = DAT_004dd988

extern "C" unsigned __int64 __cdecl getval(int, int, int);
extern "C" int __cdecl fmt(char*, int, const char*, ...);
extern "C" char* __cdecl FUN_00096f10(int x) {
    unsigned __int64 v = getval(x, 0, 0);
    fmt(((char*)&DAT_004dd988), 64, "0x%08x%08x", (unsigned)(v >> 32), (unsigned)v);
    return ((char*)&DAT_004dd988);
}