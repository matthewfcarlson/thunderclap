#include "decls/data/engine/audio.h"
// data: global = DAT_004e7b08

unsigned __int64 FUN_002672f0(const char* s, int a, int b);
class Manager {
  public:
    void FUN_002584d0(__int64*, __int64*, int, int);
};
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_00364730();
void __cdecl FUN_003615d0() {
    HULK_SIZE32(AudioHalRadicalAdpcmDecodeStream, 0x20);
    struct Pair {
        __int64 a;
        __int64 b;
    } p;
    p.a = FUN_002672f0("HalRadicalAdpcmDecodeStream", 0, 0);
    p.b = FUN_002672f0("Runtime_Hal", 0, 0);
    (*(Manager*)&DAT_004e7b08).FUN_002584d0(&p.b, &p.a, (int)sizeof(AudioHalRadicalAdpcmDecodeStream), (int)__alignof(AudioHalRadicalAdpcmDecodeStream));
    atexit(FUN_00364730);
}
