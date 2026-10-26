// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

class Params_156c50 {
  public:
    int x;
};
extern Params_156c50 TypeA_156c50;
extern Params_156c50 TypeB_156c50;
int __cdecl Check(void*, int, Params_156c50*, Params_156c50*, int);
struct InterruptAccumulatorSetAction_nv_156c50 {
    int Init(hulkfight::motion::InterruptAccumulatorSetTrack*, hulk_intptr);
};
hulkfight::motion::InterruptAccumulatorSetAction* __cdecl Alloc(int);

hulk_intptr hulkfight::motion::InterruptAccumulatorSetTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &TypeA_156c50, &TypeB_156c50, 0);
    if (result) {
        hulkfight::motion::InterruptAccumulatorSetAction* p = Alloc(0x24);
        if (p)
            return ((InterruptAccumulatorSetAction_nv_156c50*)(((hulkfight::motion::InterruptAccumulatorSetAction*)(p))))->Init(this, c);
    }
    return 0;
}
