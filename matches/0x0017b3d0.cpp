// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

class Params_17b3d0 {
  public:
    int x;
};
extern Params_17b3d0 TypeA_17b3d0;
extern Params_17b3d0 TypeB_17b3d0;
int __cdecl Check(void*, int, Params_17b3d0*, Params_17b3d0*, int);
struct ChargeClearAction_nv_17b3d0 {
    int Init(hulkfight::motion::ChargeClearTrack*, hulk_intptr);
};
hulkfight::motion::ChargeClearAction* __cdecl Alloc(int);

hulk_intptr hulkfight::motion::ChargeClearTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &TypeA_17b3d0, &TypeB_17b3d0, 0);
    if (result) {
        hulkfight::motion::ChargeClearAction* p = Alloc(0x24);
        if (p)
            return ((ChargeClearAction_nv_17b3d0*)(((hulkfight::motion::ChargeClearAction*)(p))))->Init(this, c);
    }
    return 0;
}
