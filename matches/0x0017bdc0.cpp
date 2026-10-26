// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

class Params_17bdc0 {
  public:
    int x;
};
extern Params_17bdc0 TypeA_17bdc0;
extern Params_17bdc0 TypeB_17bdc0;
int __cdecl Check(void*, int, Params_17bdc0*, Params_17bdc0*, int);
struct CriticalMassDrainAction_nv_17bdc0 {
    int Init(hulkfight::motion::CriticalMassDrainTrack*, int);
};
hulkfight::motion::CriticalMassDrainAction* __cdecl Alloc(int);

hulk_intptr hulkfight::motion::CriticalMassDrainTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &TypeA_17bdc0, &TypeB_17bdc0, 0);
    if (result) {
        hulkfight::motion::CriticalMassDrainAction* p = Alloc(0x24);
        if (p)
            return ((CriticalMassDrainAction_nv_17bdc0*)(((hulkfight::motion::CriticalMassDrainAction*)(p))))->Init(this, c);
    }
    return 0;
}
