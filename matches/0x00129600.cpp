// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

class Params_129600 {
  public:
    int x;
};
extern Params_129600 TypeA_129600;
extern Params_129600 TypeB_129600;
int __cdecl Check(void*, int, Params_129600*, Params_129600*, int);
struct ClearProjectileDistanceAction_nv_129600 {
    int Init(hulkfight::ai::ClearProjectileDistanceTrack*, hulk_intptr);
};
hulkfight::ai::ClearProjectileDistanceAction* __cdecl Alloc(int);

hulk_intptr hulkfight::ai::ClearProjectileDistanceTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &TypeA_129600, &TypeB_129600, 0);
    if (result) {
        hulkfight::ai::ClearProjectileDistanceAction* p = Alloc(0x24);
        if (p)
            return ((ClearProjectileDistanceAction_nv_129600*)(((hulkfight::ai::ClearProjectileDistanceAction*)(p))))->Init(this, c);
    }
    return 0;
}
