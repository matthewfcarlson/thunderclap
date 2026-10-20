// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_129560 {
  public:
    int x;
};
extern Params_129560 TypeA_129560;
extern Params_129560 TypeB_129560;
int __cdecl Check(void*, int, Params_129560*, Params_129560*, int);
struct AcquireTargetAction_nv_129560 {
    int Init(hulkfight::ai::AcquireTargetTrack*, int);
};
hulkfight::ai::AcquireTargetAction* __cdecl Alloc(int);

int hulkfight::ai::AcquireTargetTrack::vfunc_10(int a, int b, int c) {
    int result = Check((void*)c, 0, &TypeA_129560, &TypeB_129560, 0);
    if (result) {
        hulkfight::ai::AcquireTargetAction* p = Alloc(0x24);
        if (p)
            return ((AcquireTargetAction_nv_129560*)(p))->Init(this, c);
    }
    return 0;
}
