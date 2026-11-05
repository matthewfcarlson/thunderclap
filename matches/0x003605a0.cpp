#include "decls/data/engine/audio.h"
// data: name1 = DAT_00429f90, name2 = DAT_00429270, registry = DAT_004e6de0

struct Pair {
    unsigned a, b;
};
unsigned __int64 FUN_002672f0(const char* s, int a, int b);
struct Registry {
    void FUN_002584d0(__int64*, __int64*, int, int);
};
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_003644a0();
void __cdecl FUN_003605a0() {
    unsigned __int64 a = FUN_002672f0(((char*)&DAT_00429f90), 0, 0);
    unsigned __int64 b = FUN_002672f0(((char*)&DAT_00429270), 0, 0);
    (*(Registry*)&DAT_004e6de0).FUN_002584d0((__int64*)&b, (__int64*)&a, 16, 4);
    atexit(FUN_003644a0);
}