#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int IsType(void*, int, const void*, const void*, int);
extern void* Alloc(int);
struct Result_142330 {
    unsigned int init(hulkfight::motion::WallJumpTrack*, hulk_uintptr);
};
extern Result_142330* MakeResult(void*);
extern const int RT1;
extern const int RT2;

int hulkfight::motion::WallJumpTrack::vfunc_10(int __p0, int __p1, int __p2) { unsigned int a = (unsigned int)__p0; unsigned int b = (unsigned int)__p1; hulk_uintptr c = (unsigned int)__p2;

    if (IsType((void*)c, 0, &RT1, &RT2, 0)) {
        Result_142330* r = (Result_142330*)MakeResult((void*)0x50);
        if (r)
            return (int)(r->init(this, c));
    }
    return (int)(0);
}
