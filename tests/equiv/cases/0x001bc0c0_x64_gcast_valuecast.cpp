// eq64 must fail (integ2, D111; rev5's review): `*(CAgent**)&DAT` and a cast of the word's value `((Other_vc*)DAT[0])`
// both read the global: every cast counts, the global has no one view (view_ambiguous), never clean credit as CAgent.
//
#include "tree_prelude.h"
#include "gen/global.h"
struct Other_vc {
    int a, b;
};
extern "C" void* DAT_0052c2a4[1];
extern "C" int __cdecl Probe_1bc0c0(int k)
{
    if (k & 1)
        return ((Other_vc*)DAT_0052c2a4[0]) != 0;
    CAgent* a = *(CAgent**)&DAT_0052c2a4;
    return a == 0 ? -1 : k;
}
