// eq64 must fail (integ2, D111): one pointer word read as two different classes (CAgent and Other_amb): no one view,
// the global stays untyped and the run says so: view_ambiguous (or no input completes).
//
#include "tree_prelude.h"
#include "gen/global.h"
struct Other_amb {
    int a, b;
};
extern "C" void* DAT_0052c2a4[1];
extern "C" int __cdecl Probe_1bc0c0(int k)
{
    if (k & 1)
        return (*(Other_amb**)&DAT_0052c2a4)->b;
    CAgent* a = *(CAgent**)&DAT_0052c2a4;
    if (a == 0)
        return -1;
    return a->vfunc_10() + k;
}
