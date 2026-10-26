// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

class Params_17bfa0 {
  public:
    int x;
};
extern Params_17bfa0 TypeA_17bfa0;
extern Params_17bfa0 TypeB_17bfa0;
int __cdecl Check(void*, int, Params_17bfa0*, Params_17bfa0*, int);
struct SnapToGroundAction_nv_17bfa0 {
    int Init(hulkfight::motion::SnapToGroundTrack*, int);
};
hulkfight::motion::SnapToGroundAction* __cdecl Alloc(int);

hulk_intptr hulkfight::motion::SnapToGroundTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &TypeA_17bfa0, &TypeB_17bfa0, 0);
    if (result) {
        hulkfight::motion::SnapToGroundAction* p = Alloc(0x24);
        if (p)
            return ((SnapToGroundAction_nv_17bfa0*)(((hulkfight::motion::SnapToGroundAction*)(p))))->Init(this, c);
    }
    return 0;
}
