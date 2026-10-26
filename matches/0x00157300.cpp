// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

class Params_157300 {
  public:
    int x;
};
extern Params_157300 TypeA_157300;
extern Params_157300 TypeB_157300;
int __cdecl Check(void*, int, Params_157300*, Params_157300*, int);
class Object_157300 {
  public:
    int Init(hulkfight::motion::HitDamageTrack*, int);
};
Object_157300* __cdecl Alloc(int);

hulk_intptr hulkfight::motion::HitDamageTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &TypeA_157300, &TypeB_157300, 0);
    if (result) {
        Object_157300* p = Alloc(0x24);
        if (p)
            return p->Init(this, c);
    }
    return 0;
}
