#include "decls/data/platform/xbox/audio.h"
// data: manager_3610b0 = DAT_004e7778

extern "C" __int64 __cdecl FUN_002672f0(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
void __cdecl cleanup();
struct Manager_3610b0 {
    void FUN_002584d0(__int64*, __int64*, int, int);
};
struct Pair_3610b0 {
    __int64 property, meta;
};
void __cdecl FUN_003610b0() {
    HULK_SIZE32(OmMetaProperty, 0xa0);
    Pair_3610b0 p;
    p.property = FUN_002672f0("Property", 0, 0);
    p.meta = FUN_002672f0("Meta", 0, 0);
    (*(Manager_3610b0*)((char*)&DAT_004e7778)).FUN_002584d0(&p.meta, &p.property, (int)sizeof(OmMetaProperty), (int)__alignof(OmMetaProperty));
    atexit(cleanup);
}