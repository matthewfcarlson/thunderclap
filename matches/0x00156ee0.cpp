// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

class Params_156ee0 {
  public:
    int x;
};
extern Params_156ee0 TypeA_156ee0;
extern Params_156ee0 TypeB_156ee0;
int __cdecl Check(void*, int, Params_156ee0*, Params_156ee0*, int);
class Object_156ee0 {
  public:
    int Init(hulkfight::motion::HitPauseTrack*, hulk_intptr);
};
Object_156ee0* __cdecl Alloc(int);

hulk_intptr hulkfight::motion::HitPauseTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &TypeA_156ee0, &TypeB_156ee0, 0);
    if (result) {
        Object_156ee0* p = Alloc(0x24);
        if (p)
            return p->Init(this, c);
    }
    return 0;
}
