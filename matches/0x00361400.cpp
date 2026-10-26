#include "decls/data/engine/om.h"
// data: gRegistry = DAT_004e79d0

struct Pair {
    unsigned a, b;
};
extern "C" Pair __cdecl Make(const char*, int, int);
struct Registry {
    void Register(Pair*, Pair*, int, int);
};
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl Cleanup();
void __cdecl Init() {
    Pair first = Make("MetaType", 0, 0);
    Pair second = Make("om", 0, 0);
    (*(Registry*)&DAT_004e79d0).Register(&second, &first, 0x34, 4);
    atexit(Cleanup);
}