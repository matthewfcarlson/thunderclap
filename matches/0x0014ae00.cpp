// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

class Params_14ae00 {
  public:
    int x;
};
extern Params_14ae00 TypeA_14ae00;
extern Params_14ae00 TypeB_14ae00;
int __cdecl Check(void*, int, Params_14ae00*, Params_14ae00*, int);
struct CivilianThrowAction_nv_14ae00 {
    int Init(hulkfight::motion::CivilianThrowTrack*, int);
};
hulkfight::motion::CivilianThrowAction* __cdecl Alloc(int);

hulk_intptr hulkfight::motion::CivilianThrowTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &TypeA_14ae00, &TypeB_14ae00, 0);
    if (result) {
        hulkfight::motion::CivilianThrowAction* p = Alloc(0x24);
        if (p)
            return ((CivilianThrowAction_nv_14ae00*)(((hulkfight::motion::CivilianThrowAction*)(p))))->Init(this, c);
    }
    return 0;
}
