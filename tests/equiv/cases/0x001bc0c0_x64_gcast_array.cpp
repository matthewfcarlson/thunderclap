// eq64 must fail (integ2, D111): the scope is pointer-word globals only: `void* DAT[4]` (a larger untyped array) stays
// untyped, the raw word's "vptr" is fuzz and no input completes.
//
#include "tree_prelude.h"
#include "gen/global.h"
extern "C" void* DAT_0052c2a4[4];
extern "C" int __cdecl Probe_1bc0c0(int k)
{
    CAgent* a = *(CAgent**)&DAT_0052c2a4;
    return a->vfunc_10() + a->f_08 + k;
}
