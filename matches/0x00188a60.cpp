// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

class Params_188a60 {
  public:
    int x;
};
extern Params_188a60 TypeA_188a60;
extern Params_188a60 TypeB_188a60;
int __cdecl Check(void*, int, Params_188a60*, Params_188a60*, int);
struct PropAddToCollisionAction_nv_188a60 {
    int Init(hulkfight::motion::PropAddToCollisionTrack*, int);
};
hulkfight::motion::PropAddToCollisionAction* __cdecl Alloc(int);

hulk_intptr hulkfight::motion::PropAddToCollisionTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &TypeA_188a60, &TypeB_188a60, 0);
    if (result) {
        hulkfight::motion::PropAddToCollisionAction* p = Alloc(0x24);
        if (p)
            return ((PropAddToCollisionAction_nv_188a60*)(((hulkfight::motion::PropAddToCollisionAction*)(p))))->Init(this, c);
    }
    return 0;
}
