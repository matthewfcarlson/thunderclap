// eq64 must pass (integ2, D111): an untyped pointer word (`void* DAT[1]`, as generated) read through
// `*(CAgent**)&DAT`: the global is generated as a CAgent* (a class of include/gen, RTTI evidence), its virtual call
// reaches the slot's stub on both sides (without the model the raw word's "vptr" is fuzz: no input completes).
//
#include "tree_prelude.h"
#include "gen/global.h"
extern "C" void* DAT_0052c2a4[1];
extern "C" int __cdecl Probe_1bc0c0(int k)
{
    CAgent* a = *(CAgent**)&DAT_0052c2a4;
    if (a == 0)
        return -1;
    return a->vfunc_10() + a->f_08 + k;
}
