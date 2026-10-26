// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

class Params_188870 {
  public:
    int x;
};
extern Params_188870 TypeA_188870;
extern Params_188870 TypeB_188870;
int __cdecl Check(void*, int, Params_188870*, Params_188870*, int);
struct PropActorThinkingAction_nv_188870 {
    int Init(hulkfight::motion::PropActorThinkingTrack*, int);
};
hulkfight::motion::PropActorThinkingAction* __cdecl Alloc(int);

hulk_intptr hulkfight::motion::PropActorThinkingTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &TypeA_188870, &TypeB_188870, 0);
    if (result) {
        hulkfight::motion::PropActorThinkingAction* p = Alloc(0x24);
        if (p)
            return ((PropActorThinkingAction_nv_188870*)(((hulkfight::motion::PropActorThinkingAction*)(p))))->Init(this, c);
    }
    return 0;
}
