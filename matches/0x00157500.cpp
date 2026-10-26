// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

class Params_157500 {
  public:
    int x;
};
extern Params_157500 TypeA_157500;
extern Params_157500 TypeB_157500;
int __cdecl Check(void*, int, Params_157500*, Params_157500*, int);
struct HealthAction_nv_157500 {
    int Init(hulkfight::motion::HealthTrack*, int);
};
hulkfight::motion::HealthAction* __cdecl Alloc(int);

hulk_intptr hulkfight::motion::HealthTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &TypeA_157500, &TypeB_157500, 0);
    if (result) {
        hulkfight::motion::HealthAction* p = Alloc(0x24);
        if (p)
            return ((HealthAction_nv_157500*)(((hulkfight::motion::HealthAction*)(p))))->Init(this, c);
    }
    return 0;
}
