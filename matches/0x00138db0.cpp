#include "gen/hulkfight.h"

extern int gTypeA_138db0, gTypeB;
extern int __cdecl TypeCheck(void*, int, const void*, const void*, int);
extern void* __cdecl Alloc(int);
struct Result_138db0 {
    int Init(hulkfight::motion::FlyingAttackTrack*, int);
};

int hulkfight::motion::FlyingAttackTrack::vfunc_10(int a, int b, int c) {
    if (TypeCheck((void*)c, 0, &gTypeA_138db0, &gTypeB, 0)) {
        Result_138db0* p = (Result_138db0*)Alloc(0x3c);
        if (p)
            return p->Init(this, c);
    }
    return 0;
}
