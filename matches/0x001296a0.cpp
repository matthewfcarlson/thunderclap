// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

class Params_1296a0 {
  public:
    int x;
};
extern Params_1296a0 TypeA_1296a0;
extern Params_1296a0 TypeB_1296a0;
int __cdecl Check(void*, int, Params_1296a0*, Params_1296a0*, int);
struct TargetClearAction_nv_1296a0 {
    int Init(hulkfight::ai::TargetClearTrack*, int);
};
hulkfight::ai::TargetClearAction* __cdecl Alloc(int);

hulk_intptr hulkfight::ai::TargetClearTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &TypeA_1296a0, &TypeB_1296a0, 0);
    if (result) {
        hulkfight::ai::TargetClearAction* p = Alloc(0x24);
        if (p)
            return ((TargetClearAction_nv_1296a0*)(((hulkfight::ai::TargetClearAction*)(p))))->Init(this, c);
    }
    return 0;
}
