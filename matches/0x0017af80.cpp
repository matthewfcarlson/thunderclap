// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

class Params_17af80 {
  public:
    int x;
};
extern Params_17af80 TypeA_17af80;
extern Params_17af80 TypeB_17af80;
int __cdecl Check(void*, int, Params_17af80*, Params_17af80*, int);
class Object_17af80 {
  public:
    int Init(hulkfight::motion::LocomotionStateTrack*, hulk_intptr);
};
Object_17af80* __cdecl Alloc(int);

hulk_intptr hulkfight::motion::LocomotionStateTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &TypeA_17af80, &TypeB_17af80, 0);
    if (result) {
        Object_17af80* p = Alloc(0x24);
        if (p)
            return p->Init(this, c);
    }
    return 0;
}
