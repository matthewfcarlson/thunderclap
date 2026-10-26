// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

class Params_1575a0 {
  public:
    int x;
};
extern Params_1575a0 TypeA_1575a0;
extern Params_1575a0 TypeB_1575a0;
int __cdecl Check(void*, int, Params_1575a0*, Params_1575a0*, int);
struct ClearFightParamsHitRecordAction_nv_1575a0 {
    int Init(hulkfight::motion::ClearFightParamsHitRecordTrack*, int);
};
hulkfight::motion::ClearFightParamsHitRecordAction* __cdecl Alloc(int);

hulk_intptr hulkfight::motion::ClearFightParamsHitRecordTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &TypeA_1575a0, &TypeB_1575a0, 0);
    if (result) {
        hulkfight::motion::ClearFightParamsHitRecordAction* p = Alloc(0x24);
        if (p)
            return ((ClearFightParamsHitRecordAction_nv_1575a0*)(((hulkfight::motion::ClearFightParamsHitRecordAction*)(p))))->Init(this, c);
    }
    return 0;
}
