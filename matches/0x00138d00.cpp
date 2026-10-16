#include "gen/hulkfight.h"

struct Maker_138d00 {
    int Init(hulkfight::motion::FlyingBrakeTrack*, int);
};
extern int TypeA_138d00;
extern int TypeB_138d00;
extern int __cdecl IsType(void*, int, int*, int*, int);
extern void* __cdecl Alloc(int);

int hulkfight::motion::FlyingBrakeTrack::vfunc_10(int a, int b, int c) {
    if (IsType((void*)c, 0, &TypeA_138d00, &TypeB_138d00, 0)) {
        Maker_138d00* p = (Maker_138d00*)Alloc(0x40);
        if (p)
            return p->Init(this, c);
    }
    return 0;
}
