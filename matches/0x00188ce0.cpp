// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

class Params_188ce0 {
  public:
    int x;
};
extern Params_188ce0 TypeA_188ce0;
extern Params_188ce0 TypeB_188ce0;
int __cdecl Check(void*, int, Params_188ce0*, Params_188ce0*, int);
struct PropDropAction_nv_188ce0 {
    int Init(hulkfight::motion::PropDropTrack*, int);
};
hulkfight::motion::PropDropAction* __cdecl Alloc(int);

hulk_intptr hulkfight::motion::PropDropTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &TypeA_188ce0, &TypeB_188ce0, 0);
    if (result) {
        hulkfight::motion::PropDropAction* p = Alloc(0x24);
        if (p)
            return ((PropDropAction_nv_188ce0*)(((hulkfight::motion::PropDropAction*)(p))))->Init(this, c);
    }
    return 0;
}
