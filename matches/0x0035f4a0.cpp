#include "decls/data/engine/unknown.h"
// data: globalObj = DAT_004e5e88

typedef unsigned __int64 U64;
extern "C" U64 __cdecl FUN_002672f0(const char*, int, int);
struct Obj {
    void FUN_002584d0(U64*, U64*, int, int);
};
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_00364190();
void init() {
    HULK_SIZE32(AudioMixerBuss, 0x28);
    U64 a = FUN_002672f0("MixerBuss", 0, 0);
    U64 b = FUN_002672f0("Runtime_Mix", 0, 0);
    (*(Obj*)&DAT_004e5e88).FUN_002584d0(&b, &a, (int)sizeof(AudioMixerBuss), (int)__alignof(AudioMixerBuss));
    atexit(FUN_00364190);
}