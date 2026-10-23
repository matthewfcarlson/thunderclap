// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_157060 {
  public:
    int x;
};
extern Params_157060 TypeA_157060;
extern Params_157060 TypeB_157060;
int __cdecl Check(void*, int, Params_157060*, Params_157060*, int);
struct HitPushbackAddAction_nv_157060 {
    int Init(hulkfight::motion::HitPushbackAddTrack*, int);
};
hulkfight::motion::HitPushbackAddAction* __cdecl Alloc(int);

int hulkfight::motion::HitPushbackAddTrack::vfunc_10(int a, int b, int c) {
    int result = Check((void*)c, 0, &TypeA_157060, &TypeB_157060, 0);
    if (result) {
        hulkfight::motion::HitPushbackAddAction* p = Alloc(0x24);
        if (p)
            return ((HitPushbackAddAction_nv_157060*)(((hulkfight::motion::HitPushbackAddAction*)(p))))->Init(this, c);
    }
    return 0;
}
