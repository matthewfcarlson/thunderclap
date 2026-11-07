#include "decls/data/engine/audio.h"
#include "decls/data/platform/xbox/unknown.h"
// data: name1 = DAT_0042a9e8, name2 = DAT_004290a8, registry = DAT_004e7970

struct Pair {
    int a, b;
};
struct Registry {
    void FUN_002584d0(Pair*, Pair*, int, int);
};
extern Pair __cdecl FUN_002672f0(const char*, int, int);
extern int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl FUN_003646e0();
void FUN_003613a0() {
    HULK_SIZE32(AudioCircBufGarbageRegion, 0xc);
    Pair p = FUN_002672f0(DAT_0042a9e8, 0, 0);
    Pair q = FUN_002672f0(DAT_004290a8, 0, 0);
    (*(Registry*)((char*)&DAT_004e7970)).FUN_002584d0(&q, &p, (int)sizeof(AudioCircBufGarbageRegion), (int)__alignof(AudioCircBufGarbageRegion));
    atexit(FUN_003646e0);
}