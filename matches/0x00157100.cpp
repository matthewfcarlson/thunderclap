// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

class Params_157100 {
  public:
    int x;
};
extern Params_157100 TypeA_157100;
extern Params_157100 TypeB_157100;
int __cdecl Check(void*, int, Params_157100*, Params_157100*, int);
struct NoHitPushbackAction_nv_157100 {
    int Init(hulkfight::motion::NoHitPushbackTrack*, int);
};
hulkfight::motion::NoHitPushbackAction* __cdecl Alloc(int);

hulk_intptr hulkfight::motion::NoHitPushbackTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &TypeA_157100, &TypeB_157100, 0);
    if (result) {
        hulkfight::motion::NoHitPushbackAction* p = Alloc(0x24);
        if (p)
            return ((NoHitPushbackAction_nv_157100*)(((hulkfight::motion::NoHitPushbackAction*)(p))))->Init(this, c);
    }
    return 0;
}
