#include "decls/data/engine/audio.h"
// data: reg = DAT_004e6b80

struct Pair {
    unsigned a, b;
};
unsigned __int64 FUN_002672f0(const char* s, int a, int b);
struct Registry {
    void FUN_002584d0(__int64*, __int64*, int, int);
};
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_00364430();
void __cdecl FUN_003602b0() {
    unsigned __int64 x = FUN_002672f0(DAT_00429db4, 0, 0);
    unsigned __int64 y = FUN_002672f0(DAT_00429270, 0, 0);
    (*(Registry*)&DAT_004e6b80).FUN_002584d0((__int64*)&y, (__int64*)&x, 16, 4);
    atexit(FUN_00364430);
}