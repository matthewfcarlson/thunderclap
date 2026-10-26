// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

class Params_14afe0 {
  public:
    int x;
};
extern Params_14afe0 TypeA_14afe0;
extern Params_14afe0 TypeB_14afe0;
int __cdecl Check(void*, int, Params_14afe0*, Params_14afe0*, int);
struct CivilianAnimationAction_nv_14afe0 {
    int Init(hulkfight::motion::CivilianAnimationTrack*, hulk_intptr);
};
hulkfight::motion::CivilianAnimationAction* __cdecl Alloc(int);

hulk_intptr hulkfight::motion::CivilianAnimationTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &TypeA_14afe0, &TypeB_14afe0, 0);
    if (result) {
        hulkfight::motion::CivilianAnimationAction* p = Alloc(0x24);
        if (p)
            return ((CivilianAnimationAction_nv_14afe0*)(((hulkfight::motion::CivilianAnimationAction*)(p))))->Init(this, c);
    }
    return 0;
}
