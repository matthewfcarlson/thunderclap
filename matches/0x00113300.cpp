// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

class Params_113300 {
  public:
    int x;
};
extern Params_113300 TypeA_113300;
extern Params_113300 TypeB_113300;
int __cdecl Check(void*, int, Params_113300*, Params_113300*, int);
struct AIHistorySetAction_nv_113300 {
    int Init(hulkfight::ai::AIHistorySetTrack*, hulk_intptr);
};
hulkfight::ai::AIHistorySetAction* __cdecl Alloc(int);

hulk_intptr hulkfight::ai::AIHistorySetTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &TypeA_113300, &TypeB_113300, 0);
    if (result) {
        hulkfight::ai::AIHistorySetAction* p = Alloc(0x24);
        if (p)
            return ((AIHistorySetAction_nv_113300*)(((hulkfight::ai::AIHistorySetAction*)(p))))->Init(this, c);
    }
    return 0;
}
