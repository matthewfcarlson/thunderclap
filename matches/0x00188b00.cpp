// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

class Params_188b00 {
  public:
    int x;
};
extern Params_188b00 TypeA_188b00;
extern Params_188b00 TypeB_188b00;
int __cdecl Check(void*, int, Params_188b00*, Params_188b00*, int);
class Object_188b00 {
  public:
    int Init(hulkfight::motion::PropSetStateByIndexTrack*, int);
};
Object_188b00* __cdecl Alloc(int);

hulk_intptr hulkfight::motion::PropSetStateByIndexTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &TypeA_188b00, &TypeB_188b00, 0);
    if (result) {
        Object_188b00* p = Alloc(0x24);
        if (p)
            return p->Init(this, c);
    }
    return 0;
}
