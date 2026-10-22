// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_188870 {
  public:
    int x;
};
extern Params_188870 TypeA_188870;
extern Params_188870 TypeB_188870;
int __cdecl Check(void*, int, Params_188870*, Params_188870*, int);
struct PropActorThinkingAction_188870 {
    int Init(hulkfight::motion::PropActorThinkingTrack*, int);
};
hulkfight::motion::PropActorThinkingAction* __cdecl Alloc(int);

int hulkfight::motion::PropActorThinkingTrack::vfunc_10(int a, int b, int c) {
    int result = Check((void*)c, 0, &TypeA_188870, &TypeB_188870, 0);
    if (result) {
        hulkfight::motion::PropActorThinkingAction* p = Alloc(0x24);
        if (p)
            return ((PropActorThinkingAction_188870*)(p))->Init(this, c);
    }
    return 0;
}
