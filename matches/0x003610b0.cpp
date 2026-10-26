#include "decls/data/platform/xbox/audio.h"
// data: manager_3610b0 = DAT_004e7778

extern "C" __int64 __cdecl Find(const char*, int, int);
extern "C" int __cdecl atexit(void(__cdecl*)());
void __cdecl cleanup();
struct Manager_3610b0 {
    void Init(__int64*, __int64*, int, int);
};
struct Pair_3610b0 {
    __int64 property, meta;
};
void __cdecl FUN_003610b0() {
    Pair_3610b0 p;
    p.property = Find("Property", 0, 0);
    p.meta = Find("Meta", 0, 0);
    (*(Manager_3610b0*)((char*)&DAT_004e76e8 + 144)).Init(&p.meta, &p.property, 0xa0, 4);
    atexit(cleanup);
}