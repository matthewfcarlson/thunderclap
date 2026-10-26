// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

class Params_12ca10 {
  public:
    int x;
};
extern Params_12ca10 TypeA_12ca10;
extern Params_12ca10 TypeB_12ca10;
int __cdecl Check(void*, int, Params_12ca10*, Params_12ca10*, int);
struct ThreatDodgeAction_nv_12ca10 {
    int Init(hulkfight::ai::ThreatDodgeTrack*, hulk_intptr);
};
hulkfight::ai::ThreatDodgeAction* __cdecl Alloc(int);

hulk_intptr hulkfight::ai::ThreatDodgeTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &TypeA_12ca10, &TypeB_12ca10, 0);
    if (result) {
        hulkfight::ai::ThreatDodgeAction* p = Alloc(0x24);
        if (p)
            return ((ThreatDodgeAction_nv_12ca10*)(((hulkfight::ai::ThreatDodgeAction*)(p))))->Init(this, c);
    }
    return 0;
}
