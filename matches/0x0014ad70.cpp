#include "gen/hulkfight.h"

struct GrappleThrowAction_nv_14ad70 {
    int Init(hulkfight::motion::GrappleThrowTrack*, int);
};
extern int __cdecl GetThing(int);
extern void* __cdecl Alloc(int);

int hulkfight::motion::GrappleThrowTrack::vfunc_10(int a, int b, int c) {
    int x = GetThing(c);
    if (x) {
        hulkfight::motion::GrappleThrowAction* p = (hulkfight::motion::GrappleThrowAction*)Alloc(0x54);
        if (p)
            return ((GrappleThrowAction_nv_14ad70*)(p))->Init(this, x);
    }
    return 0;
}
