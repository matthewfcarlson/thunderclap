// eq64 must fail (rev5's probe, D111): one pointer word read as two classes whose reads don't differ (null checks
// under both casts): no one view, the global stays untyped, and the run says so by the rule: view_ambiguous.
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
        return (*(Other_amb**)&DAT_0052c2a4) != 0;
    CAgent* a = *(CAgent**)&DAT_0052c2a4;
    return a == 0 ? -1 : k;
}
