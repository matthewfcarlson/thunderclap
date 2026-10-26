// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

class Params_17b020 {
  public:
    int x;
};
extern Params_17b020 TypeA_17b020;
extern Params_17b020 TypeB_17b020;
int __cdecl Check(void*, int, Params_17b020*, Params_17b020*, int);
class Object_17b020 {
  public:
    int Init(hulkfight::motion::MotionStateTrack*, int);
};
Object_17b020* __cdecl Alloc(int);

hulk_intptr hulkfight::motion::MotionStateTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &TypeA_17b020, &TypeB_17b020, 0);
    if (result) {
        Object_17b020* p = Alloc(0x24);
        if (p)
            return p->Init(this, c);
    }
    return 0;
}
