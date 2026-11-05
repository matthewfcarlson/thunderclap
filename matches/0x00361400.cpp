#include "decls/data/engine/om.h"
// data: gRegistry = DAT_004e79d0

struct Pair {
    unsigned a, b;
};
extern "C" Pair __cdecl FUN_002672f0(const char*, int, int);
struct Registry {
    void FUN_002584d0(Pair*, Pair*, int, int);
};
extern "C" int __cdecl atexit(void(__cdecl*)());
extern "C" void __cdecl Cleanup();
void __cdecl Init() {
    Pair first = FUN_002672f0("MetaType", 0, 0);
    Pair second = FUN_002672f0("om", 0, 0);
    (*(Registry*)&DAT_004e79d0).FUN_002584d0(&second, &first, 0x34, 4);
    atexit(Cleanup);
}