// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

class Params_17bf00 {
  public:
    int x;
};
extern Params_17bf00 TypeA_17bf00;
extern Params_17bf00 TypeB_17bf00;
int __cdecl Check(void*, int, Params_17bf00*, Params_17bf00*, int);
struct VisibilityAction_nv_17bf00 {
    int Init(hulkfight::motion::VisibilityTrack*, hulk_intptr);
};
hulkfight::motion::VisibilityAction* __cdecl Alloc(int);

hulk_intptr hulkfight::motion::VisibilityTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &TypeA_17bf00, &TypeB_17bf00, 0);
    if (result) {
        hulkfight::motion::VisibilityAction* p = Alloc(0x24);
        if (p)
            return ((VisibilityAction_nv_17bf00*)(((hulkfight::motion::VisibilityAction*)(p))))->Init(this, c);
    }
    return 0;
}
