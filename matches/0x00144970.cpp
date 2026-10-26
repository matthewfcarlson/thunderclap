// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

class Params_144970 {
  public:
    int x;
};
extern Params_144970 TypeA_144970;
extern Params_144970 TypeB_144970;
int __cdecl Check(void*, int, Params_144970*, Params_144970*, int);
class Object_144970 {
  public:
    int Init(hulkfight::motion::WorldDamageTrack*, int);
};
Object_144970* __cdecl Alloc(int);

hulk_intptr hulkfight::motion::WorldDamageTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &TypeA_144970, &TypeB_144970, 0);
    if (result) {
        Object_144970* p = Alloc(0x24);
        if (p)
            return p->Init(this, c);
    }
    return 0;
}
