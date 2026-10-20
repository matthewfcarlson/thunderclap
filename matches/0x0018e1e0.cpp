// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_18e1e0 {
  public:
    int x;
};
extern Params_18e1e0 TypeA_18e1e0;
extern Params_18e1e0 TypeB_18e1e0;
int __cdecl Check(void*, int, Params_18e1e0*, Params_18e1e0*, int);
struct TimerSetAction_nv_18e1e0 {
    int Init(hulkfight::motion::TimerSetTrack*, int);
};
hulkfight::motion::TimerSetAction* __cdecl Alloc(int);

int hulkfight::motion::TimerSetTrack::vfunc_10(int a, int b, int c) {
    int result = Check((void*)c, 0, &TypeA_18e1e0, &TypeB_18e1e0, 0);
    if (result) {
        hulkfight::motion::TimerSetAction* p = Alloc(0x24);
        if (p)
            return ((TimerSetAction_nv_18e1e0*)(p))->Init(this, c);
    }
    return 0;
}
