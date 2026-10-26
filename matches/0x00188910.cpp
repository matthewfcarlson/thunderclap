// Same code shape as 0x001134e0 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern int FUN_00344e74(int, int, const void*, const void*, int);
extern void* FUN_0008d690(int);
extern int RTTI_Type1;
extern int RTTI_Type2;
class AllocObj_188910 {
  public:
    int init(hulkfight::motion::PropAnimationTrack*, hulk_intptr);
};

hulk_intptr hulkfight::motion::PropAnimationTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    if (FUN_00344e74(c, 0, &RTTI_Type1, &RTTI_Type2, 0)) {
        AllocObj_188910* p = (AllocObj_188910*)FUN_0008d690(0x2c);
        if (p)
            return p->init(this, c);
    }
    return 0;
}
