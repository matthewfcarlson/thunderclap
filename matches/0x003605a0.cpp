#include "decls/data/engine/audio.h"
// data: name1 = DAT_00429f90, name2 = DAT_00429270, registry = DAT_004e6de0

struct Pair {
    unsigned a, b;
};
extern Pair __cdecl make(const char*, int, int);
struct Registry {
    void add(Pair*, Pair*, int, int);
};
extern "C" int __cdecl atexit(void(__cdecl*)());
extern void __cdecl cleanup();
void __cdecl FUN_003605a0() {
    Pair a = make(((char*)&DAT_00429f90), 0, 0);
    Pair b = make(((char*)&DAT_00429270), 0, 0);
    (*(Registry*)&DAT_004e6de0).add(&b, &a, 16, 4);
    atexit(cleanup);
}