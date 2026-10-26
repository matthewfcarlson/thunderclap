// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

class Params_188ba0 {
  public:
    int x;
};
extern Params_188ba0 TypeA_188ba0;
extern Params_188ba0 TypeB_188ba0;
int __cdecl Check(void*, int, Params_188ba0*, Params_188ba0*, int);
struct PropSetStateByNameAction_nv_188ba0 {
    int Init(hulkfight::motion::PropSetStateByNameTrack*, hulk_intptr);
};
hulkfight::motion::PropSetStateByNameAction* __cdecl Alloc(int);

hulk_intptr hulkfight::motion::PropSetStateByNameTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &TypeA_188ba0, &TypeB_188ba0, 0);
    if (result) {
        hulkfight::motion::PropSetStateByNameAction* p = Alloc(0x24);
        if (p)
            return ((PropSetStateByNameAction_nv_188ba0*)(((hulkfight::motion::PropSetStateByNameAction*)(p))))->Init(this, c);
    }
    return 0;
}
