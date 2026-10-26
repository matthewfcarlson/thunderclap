// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

class Params_17b700 {
  public:
    int x;
};
extern Params_17b700 TypeA_17b700;
extern Params_17b700 TypeB_17b700;
int __cdecl Check(void*, int, Params_17b700*, Params_17b700*, int);
struct TeleportAction_nv_17b700 {
    int Init(hulkfight::motion::TeleportTrack*, hulk_intptr);
};
hulkfight::motion::TeleportAction* __cdecl Alloc(int);

hulk_intptr hulkfight::motion::TeleportTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &TypeA_17b700, &TypeB_17b700, 0);
    if (result) {
        hulkfight::motion::TeleportAction* p = Alloc(0x24);
        if (p)
            return ((TeleportAction_nv_17b700*)(((hulkfight::motion::TeleportAction*)(p))))->Init(this, c);
    }
    return 0;
}
