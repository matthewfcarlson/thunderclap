#include "compat/ptr.h"
#include "gen/owners.h"
struct Iter_261460 {
    int v;
};

int FUN_002611b0(int* p);
int FUN_002673a0(int a, int b);
hulk_intptr FUN_002610e0(int m, int* k);
void FUN_00261120(int m, int* k, Iter_261460* it);

struct Helper_261460 {
    char d[16];
    int Get();
};

extern "C" int __cdecl FUN_00261460(int* p) {
    int a = FUN_002611b0(p);
    int b = FUN_002611b0(p);
    char tmp[12];
    int key;
    Helper_261460* h = ((Helper_261460 *)((owners::String_23fc40 *)(((Helper_261460*)tmp)))->FUN_0023fc40((const char *)(hulk_uintptr)(int)a, (hulk_intptr)2));
    int r = h->Get();
    key = FUN_002673a0(r, 0);
    ((owners::Str_240060 *)(((Helper_261460*)tmp)))->FUN_00240060();
    Helper_261460* f = (Helper_261460*)FUN_002610e0(*p, &key);
    if (!f) {
        Helper_261460* g = ((Helper_261460 *)((owners::String_23fc40 *)(((Helper_261460*)tmp)))->FUN_0023fc40((const char *)(hulk_uintptr)(int)b, (hulk_intptr)2));
        FUN_00261120(*p, &key, (Iter_261460*)g);
        ((owners::Str_240060 *)(((Helper_261460*)tmp)))->FUN_00240060();
        return b;
    }
    ((owners::String_23fe50 *)f)->FUN_0023fe50((const char *)(hulk_uintptr)(int)b);
    return b;
}
