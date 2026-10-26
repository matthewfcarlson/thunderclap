// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

class Params_1889c0 {
  public:
    int x;
};
extern Params_1889c0 TypeA_1889c0;
extern Params_1889c0 TypeB_1889c0;
int __cdecl Check(void*, int, Params_1889c0*, Params_1889c0*, int);
struct PropAddToMissileCountAction_nv_1889c0 {
    int Init(hulkfight::motion::PropAddToMissileCountTrack*, int);
};
hulkfight::motion::PropAddToMissileCountAction* __cdecl Alloc(int);

hulk_intptr hulkfight::motion::PropAddToMissileCountTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &TypeA_1889c0, &TypeB_1889c0, 0);
    if (result) {
        hulkfight::motion::PropAddToMissileCountAction* p = Alloc(0x24);
        if (p)
            return ((PropAddToMissileCountAction_nv_1889c0*)(((hulkfight::motion::PropAddToMissileCountAction*)(p))))->Init(this, c);
    }
    return 0;
}
