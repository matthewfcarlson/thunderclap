#include "compat/ptr.h"
#include "gen/hulkfight.h"

typedef unsigned int u32_17b1e0;
struct Result_17b1e0 {
    int Init(hulkfight::motion::JointRelativeTrack*, u32_17b1e0);
};
extern int __cdecl Check5(u32_17b1e0, int, void*, void*, int);
extern void* __cdecl Alloc(int);
extern char g_a_17b1e0;
extern char g_b_17b1e0;

hulk_intptr hulkfight::motion::JointRelativeTrack::vfunc_10(hulk_intptr __p0, hulk_intptr __p1, hulk_intptr __p2) { u32_17b1e0 a = (u32_17b1e0)__p0; u32_17b1e0 b = (u32_17b1e0)__p1; u32_17b1e0 c = (u32_17b1e0)__p2;

    if (Check5(c, 0, &g_b_17b1e0, &g_a_17b1e0, 0)) {
        Result_17b1e0* r = (Result_17b1e0*)Alloc(100);
        if (r)
            return r->Init(this, c);
    }
    return 0;
}
