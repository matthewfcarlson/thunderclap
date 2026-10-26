// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "compat/ptr.h"
#include "gen/hulkfight.h"

class Params_191720 {
  public:
    int x;
};
extern Params_191720 TypeA_191720;
extern Params_191720 TypeB_191720;
int __cdecl Check(void*, int, Params_191720*, Params_191720*, int);
struct SimulationAction_nv_191720 {
    int Init(hulkfight::motion::SimulationTrack*, hulk_intptr);
};
hulkfight::motion::SimulationAction* __cdecl Alloc(int);

hulk_intptr hulkfight::motion::SimulationTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    int result = Check((void*)c, 0, &TypeA_191720, &TypeB_191720, 0);
    if (result) {
        hulkfight::motion::SimulationAction* p = Alloc(0x24);
        if (p)
            return ((SimulationAction_nv_191720*)(((hulkfight::motion::SimulationAction*)(p))))->Init(this, c);
    }
    return 0;
}
