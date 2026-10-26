// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

class Params_113260 {
  public:
    int x;
};
extern Params_113260 TypeA_113260;
extern Params_113260 TypeB_113260;
int __cdecl Check(void*, int, Params_113260*, Params_113260*, int);
struct TokenAction_nv_113260 {
    int Init(hulkfight::ai::TokenTrack*, hulk_intptr);
};
hulkfight::ai::TokenAction* __cdecl Alloc(int);

hulk_intptr hulkfight::ai::TokenTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &TypeA_113260, &TypeB_113260, 0);
    if (result) {
        hulkfight::ai::TokenAction* p = Alloc(0x24);
        if (p)
            return ((TokenAction_nv_113260*)(((hulkfight::ai::TokenAction*)(p))))->Init(this, c);
    }
    return 0;
}
