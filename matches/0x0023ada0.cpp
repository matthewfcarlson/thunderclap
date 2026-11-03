#include "gen/fight.h"
#include "gen/owners.h"

struct B_23ada0 {
};
extern "C" void* F238190(int a);
extern "C" void* F266e00(void* a, int n);
extern "C" void F267090(void* p);
struct ScriptReader_nv_23ada0 {
    bool Size(int a, int* n);
};

bool fight::ScriptReader::FUN_0023ada0(int a, void* __p1) { B_23ada0 * b = (B_23ada0 *)__p1;

    int n = 0;
    if (!((ScriptReader_nv_23ada0*)this)->Size(a, &n))
        return false;
    int len = n + 1;
    void* p = F266e00(F238190(1), len);
    bool r = ((fight::ScriptReader *)(((ScriptReader_nv_23ada0*)this)))->FUN_0023ad30(a, (char *)p, len);
    if (!r)
        return false;
    ((owners::Target_27b040 *)b)->FUN_0027b040((hulk_uintptr)p);
    F267090(p);
    return r;
}
