// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_191720 {
  public:
    int x;
};
extern Params_191720 TypeA_191720;
extern Params_191720 TypeB_191720;
int __cdecl Check(void*, int, Params_191720*, Params_191720*, int);
struct SimulationAction_191720 {
    int Init(hulkfight::motion::SimulationTrack*, int);
};
hulkfight::motion::SimulationAction* __cdecl Alloc(int);

int hulkfight::motion::SimulationTrack::vfunc_10(int a, int b, int c) {
    int result = Check((void*)c, 0, &TypeA_191720, &TypeB_191720, 0);
    if (result) {
        hulkfight::motion::SimulationAction* p = Alloc(0x24);
        if (p)
            return ((SimulationAction_191720*)(p))->Init(this, c);
    }
    return 0;
}
