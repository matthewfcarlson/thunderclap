// Same code shape as 0x00138d00 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

struct Maker_138e60 {
    int Init(hulkfight::motion::FlyingDashTrack*, hulk_intptr);
};
extern int TypeA_138e60;
extern int TypeB_138e60;
extern int __cdecl IsType(void*, int, int*, int*, int);
extern void* __cdecl Alloc(int);

hulk_intptr hulkfight::motion::FlyingDashTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    if (IsType((void*)c, 0, &TypeA_138e60, &TypeB_138e60, 0)) {
        Maker_138e60* p = (Maker_138e60*)Alloc(0x40);
        if (p)
            return p->Init(this, c);
    }
    return 0;
}
