// Same code shape as 0x00138d00 (propagated; names are from that function)
#include "gen/hulkfight.h"

struct HitThrowAction_nv_1573a0 {
    int Init(hulkfight::motion::HitThrowTrack*, int);
};
extern int TypeA_1573a0;
extern int TypeB_1573a0;
extern int __cdecl IsType(void*, int, int*, int*, int);
extern void* __cdecl Alloc(int);

int hulkfight::motion::HitThrowTrack::vfunc_10(int a, int b, int c) {
    if (IsType((void*)c, 0, &TypeA_1573a0, &TypeB_1573a0, 0)) {
        hulkfight::motion::HitThrowAction* p = (hulkfight::motion::HitThrowAction*)Alloc(0x40);
        if (p)
            return ((HitThrowAction_nv_1573a0*)(p))->Init(this, c);
    }
    return 0;
}
