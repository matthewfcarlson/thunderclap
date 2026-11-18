// eq64 must fail (integ2, D111): the same through a locally declared stand-in (Agent_lc): a view taken on trust
// (D93's rule), never a clean equivalent: unsupported, view_trusted.
//
#include "tree_prelude.h"
struct Agent_lc {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual int vfunc_10();
    int f_08;
};
extern "C" void* DAT_0052c2a4[1];
extern "C" int __cdecl Probe_1bc0c0(int k)
{
    Agent_lc* a = *(Agent_lc**)&DAT_0052c2a4;
    if (a == 0)
        return -1;
    return a->vfunc_10() + a->f_08 + k;
}
