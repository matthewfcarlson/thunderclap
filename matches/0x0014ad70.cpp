#include "compat/ptr.h"
#include "gen/hulkfight.h"

struct GrappleThrowAction_nv_14ad70 {
    int Init(hulkfight::motion::GrappleThrowTrack*, int);
};
extern int __cdecl GetThing(int);
extern void* __cdecl Alloc(int);

hulk_intptr hulkfight::motion::GrappleThrowTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int x = GetThing(c);
    if (x) {
        hulkfight::motion::GrappleThrowAction* p = (hulkfight::motion::GrappleThrowAction*)Alloc(0x54);
        if (p)
            return ((GrappleThrowAction_nv_14ad70*)(((hulkfight::motion::GrappleThrowAction*)(p))))->Init(this, x);
    }
    return 0;
}
