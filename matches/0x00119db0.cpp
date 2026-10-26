// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

class Params_119db0 {
  public:
    int x;
};
extern Params_119db0 TypeA_119db0;
extern Params_119db0 TypeB_119db0;
int __cdecl Check(void*, int, Params_119db0*, Params_119db0*, int);
struct MotionFacingAction_nv_119db0 {
    int Init(hulkfight::ai::MotionFacingTrack*, int);
};
hulkfight::ai::MotionFacingAction* __cdecl Alloc(int);

hulk_intptr hulkfight::ai::MotionFacingTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &TypeA_119db0, &TypeB_119db0, 0);
    if (result) {
        hulkfight::ai::MotionFacingAction* p = Alloc(0x24);
        if (p)
            return ((MotionFacingAction_nv_119db0*)(((hulkfight::ai::MotionFacingAction*)(p))))->Init(this, c);
    }
    return 0;
}
