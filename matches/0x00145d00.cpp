// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

class Params_145d00 {
  public:
    int x;
};
extern Params_145d00 TypeA_145d00;
extern Params_145d00 TypeB_145d00;
int __cdecl Check(void*, int, Params_145d00*, Params_145d00*, int);
struct MotionTrailStopAction_nv_145d00 {
    int Init(hulkfight::motion::MotionTrailStopTrack*, hulk_intptr);
};
hulkfight::motion::MotionTrailStopAction* __cdecl Alloc(int);

hulk_intptr hulkfight::motion::MotionTrailStopTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &TypeA_145d00, &TypeB_145d00, 0);
    if (result) {
        hulkfight::motion::MotionTrailStopAction* p = Alloc(0x24);
        if (p)
            return ((MotionTrailStopAction_nv_145d00*)(((hulkfight::motion::MotionTrailStopAction*)(p))))->Init(this, c);
    }
    return 0;
}
