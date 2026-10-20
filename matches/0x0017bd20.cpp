// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_17bd20 {
  public:
    int x;
};
extern Params_17bd20 TypeA_17bd20;
extern Params_17bd20 TypeB_17bd20;
int __cdecl Check(void*, int, Params_17bd20*, Params_17bd20*, int);
struct SuckAction_nv_17bd20 {
    int Init(hulkfight::motion::SuckTrack*, int);
};
hulkfight::motion::SuckAction* __cdecl Alloc(int);

int hulkfight::motion::SuckTrack::vfunc_10(int a, int b, int c) {
    int result = Check((void*)c, 0, &TypeA_17bd20, &TypeB_17bd20, 0);
    if (result) {
        hulkfight::motion::SuckAction* p = Alloc(0x24);
        if (p)
            return ((SuckAction_nv_17bd20*)(p))->Init(this, c);
    }
    return 0;
}
