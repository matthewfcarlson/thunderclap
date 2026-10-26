// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

class Params_19bc00 {
  public:
    int x;
};
extern Params_19bc00 TypeA_19bc00;
extern Params_19bc00 TypeB_19bc00;
int __cdecl Check(void*, int, Params_19bc00*, Params_19bc00*, int);
struct MissilePunchAction_nv_19bc00 {
    int Init(hulkfight::motion::MissilePunchTrack*, hulk_intptr);
};
hulkfight::motion::MissilePunchAction* __cdecl Alloc(int);

hulk_intptr hulkfight::motion::MissilePunchTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &TypeA_19bc00, &TypeB_19bc00, 0);
    if (result) {
        hulkfight::motion::MissilePunchAction* p = Alloc(0x24);
        if (p)
            return ((MissilePunchAction_nv_19bc00*)(((hulkfight::motion::MissilePunchAction*)(p))))->Init(this, c);
    }
    return 0;
}
