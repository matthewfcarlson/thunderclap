#include "decls/data/engine/audio.h"
// data: reg = DAT_004e6b80

struct Pair {
    unsigned a, b;
};
extern Pair __cdecl make(const char*, int, int);
struct Registry {
    void init(const Pair*, const Pair*, int, int);
};
extern "C" int __cdecl atexit(void(__cdecl*)());
extern void __cdecl cleanup();
void __cdecl FUN_003602b0() {
    Pair x = make(DAT_00429db4, 0, 0);
    Pair y = make(DAT_00429270, 0, 0);
    (*(Registry*)&DAT_004e6b80).init(&y, &x, 16, 4);
    atexit(cleanup);
}