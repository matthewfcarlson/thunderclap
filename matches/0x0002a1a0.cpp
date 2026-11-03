#include "decls/address.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "gen/owners.h"
struct Pair {
    char pad[8];
    int a, b;
};
extern "C" void __cdecl FUN_00096d50(void*, int, int, int);
class C {
  public:
    float* Fn(const char*);
    Pair* Make(__int64);
};
float* C::Fn(const char* s) {
    __int64 v = FUN_002672f0(s, 0, 0);
    Pair* p = Make(v);
    if (p)
        p = ((Pair *)((owners::C_35ef0 *)p)->FUN_00035ef0((hulk_intptr)0));
    if (!p)
        return ((float*)&DAT_003f335c);
    FUN_00096d50(((char*)&DAT_004dc268), 0x20, p->a, p->b);
    return (float*)&(*(char*)&DAT_004dc268);
}