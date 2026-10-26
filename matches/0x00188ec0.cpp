// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

class Params_188ec0 {
  public:
    int x;
};
extern Params_188ec0 TypeA_188ec0;
extern Params_188ec0 TypeB_188ec0;
int __cdecl Check(void*, int, Params_188ec0*, Params_188ec0*, int);
struct PropDestroyAction_nv_188ec0 {
    int Init(hulkfight::motion::PropDestroyTrack*, int);
};
hulkfight::motion::PropDestroyAction* __cdecl Alloc(int);

hulk_intptr hulkfight::motion::PropDestroyTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &TypeA_188ec0, &TypeB_188ec0, 0);
    if (result) {
        hulkfight::motion::PropDestroyAction* p = Alloc(0x24);
        if (p)
            return ((PropDestroyAction_nv_188ec0*)(((hulkfight::motion::PropDestroyAction*)(p))))->Init(this, c);
    }
    return 0;
}
