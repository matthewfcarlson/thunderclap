#include "decls/data/engine/audio.h"
#include "decls/data/platform/xbox/unknown.h"
// data: name1 = DAT_0042a9e8, name2 = DAT_004290a8, registry = DAT_004e7970

struct Pair {
    int a, b;
};
struct Registry {
    void Init(Pair*, Pair*, int, int);
};
extern Pair __cdecl Get(const char*, int, int);
extern int __cdecl atexit(void(__cdecl*)());
extern void __cdecl Cleanup();
void FUN_003613a0() {
    Pair p = Get(DAT_0042a9e8, 0, 0);
    Pair q = Get(DAT_004290a8, 0, 0);
    (*(Registry*)((char*)&DAT_004e78e0 + 144)).Init(&q, &p, 12, 4);
    atexit(Cleanup);
}