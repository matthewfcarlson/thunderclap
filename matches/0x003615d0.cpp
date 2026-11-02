#include "decls/data/engine/audio.h"
// data: global = DAT_004e7b08

extern "C" __int64 __cdecl lookup(const char*, int, int);
class Manager {
  public:
    void init(__int64*, __int64*, int, int);
};
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_00364730();
void __cdecl FUN_003615d0() {
    struct Pair {
        __int64 a;
        __int64 b;
    } p;
    p.a = lookup("HalRadicalAdpcmDecodeStream", 0, 0);
    p.b = lookup("Runtime_Hal", 0, 0);
    (*(Manager*)&DAT_004e7b08).init(&p.b, &p.a, 32, 4);
    atexit(FUN_00364730);
}
