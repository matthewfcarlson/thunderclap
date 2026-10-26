// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

class Params_189000 {
  public:
    int x;
};
extern Params_189000 TypeA_189000;
extern Params_189000 TypeB_189000;
int __cdecl Check(void*, int, Params_189000*, Params_189000*, int);
struct ShieldArcAction_nv_189000 {
    int Init(hulkfight::motion::ShieldArcTrack*, hulk_intptr);
};
hulkfight::motion::ShieldArcAction* __cdecl Alloc(int);

hulk_intptr hulkfight::motion::ShieldArcTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &TypeA_189000, &TypeB_189000, 0);
    if (result) {
        hulkfight::motion::ShieldArcAction* p = Alloc(0x24);
        if (p)
            return ((ShieldArcAction_nv_189000*)(((hulkfight::motion::ShieldArcAction*)(p))))->Init(this, c);
    }
    return 0;
}
