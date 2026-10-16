#include "gen/global.h"

struct ImageSelector_nv_ee180 {
    void Update();
};
extern void FUN_000c8710(void*, int);

void ImageSelector::vfunc_19(int p2, int p3, int p4, int p5, int __p4) { char p6 = (char)__p4;

    if (p2 && p3 >= 0 && p3 < 8 && p4 >= 0 && p4 < 8) {
        FUN_000c8710((char*)this + 0x150 + (p4 + p3 * 8) * 4, p2);
        *((char*)this + 0x250 + p4 + p3 * 8) = (char)p5;
        if (p6) {
            *(int*)((char*)this + 0x2a4) = *(int*)((char*)this + 0x2a8) =
                *(int*)((char*)this + 0x298) * p3 + p4;
            ((ImageSelector_nv_ee180*)this)->Update();
        }
        ++*(int*)((char*)this + 0x290);
    }
}
