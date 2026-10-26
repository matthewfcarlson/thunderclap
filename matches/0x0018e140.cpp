// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

class Params_18e140 {
  public:
    int x;
};
extern Params_18e140 TypeA_18e140;
extern Params_18e140 TypeB_18e140;
int __cdecl Check(void*, int, Params_18e140*, Params_18e140*, int);
struct VarAssignAction_nv_18e140 {
    int Init(hulkfight::motion::VarAssignTrack*, hulk_intptr);
};
hulkfight::motion::VarAssignAction* __cdecl Alloc(int);

hulk_intptr hulkfight::motion::VarAssignTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &TypeA_18e140, &TypeB_18e140, 0);
    if (result) {
        hulkfight::motion::VarAssignAction* p = Alloc(0x24);
        if (p)
            return ((VarAssignAction_nv_18e140*)(((hulkfight::motion::VarAssignAction*)(p))))->Init(this, c);
    }
    return 0;
}
