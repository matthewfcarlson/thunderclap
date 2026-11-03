#include "gen/owners.h"
struct Obj_1d1d50 {
    char pad[8];
    void* m;
};
extern void __cdecl f(void*, unsigned int);
extern void __cdecl g(void*, int);
bool owners::Thing_1d1d50::FUN_001d1d50(hulk_uintptr a, hulk_uintptr b) {
    f(m, ((unsigned int)a));
    f(m, ((unsigned int)b));
    g(m, -3);
    return true;
}
