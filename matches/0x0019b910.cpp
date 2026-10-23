// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_19b910 {
  public:
    int x;
};
extern Params_19b910 TypeA_19b910;
extern Params_19b910 TypeB_19b910;
int __cdecl Check(void*, int, Params_19b910*, Params_19b910*, int);
struct MissileThrowAction_nv_19b910 {
    int Init(hulkfight::motion::MissileThrowTrack*, int);
};
hulkfight::motion::MissileThrowAction* __cdecl Alloc(int);

int hulkfight::motion::MissileThrowTrack::vfunc_10(int a, int b, int c) {
    int result = Check((void*)c, 0, &TypeA_19b910, &TypeB_19b910, 0);
    if (result) {
        hulkfight::motion::MissileThrowAction* p = Alloc(0x24);
        if (p)
            return ((MissileThrowAction_nv_19b910*)(((hulkfight::motion::MissileThrowAction*)(p))))->Init(this, c);
    }
    return 0;
}
