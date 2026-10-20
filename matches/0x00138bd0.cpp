#include "gen/hulkfight.h"

struct HoverAction_nv_138bd0 {
    int build(int, int);
};
extern int __cdecl Lookup(int);
extern hulkfight::motion::HoverAction* __cdecl Alloc(int);

int hulkfight::motion::GrappleHoverTrack::vfunc_10(int a, int b, int c) {
    int x = Lookup(c);
    if (x) {
        hulkfight::motion::HoverAction* p = Alloc(0x24);
        if (p) {
            int f = this->f_14;
            return ((HoverAction_nv_138bd0*)(p))->build(f, x);
        }
    }
    return 0;
}
