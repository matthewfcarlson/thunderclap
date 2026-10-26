#include "compat/ptr.h"
#include "gen/hulkfight.h"

struct HoverAction_nv_138bd0 {
    int build(int, int);
};
extern int __cdecl Lookup(int);
extern hulkfight::motion::HoverAction* __cdecl Alloc(int);

hulk_intptr hulkfight::motion::GrappleHoverTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int x = Lookup(c);
    if (x) {
        hulkfight::motion::HoverAction* p = Alloc(0x24);
        if (p) {
            int f = this->f_14;
            return ((HoverAction_nv_138bd0*)(((hulkfight::motion::HoverAction*)(p))))->build(f, x);
        }
    }
    return 0;
}
