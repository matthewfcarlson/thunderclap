// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_1917c0 {
  public:
    int x;
};
extern Params_1917c0 TypeA_1917c0;
extern Params_1917c0 TypeB_1917c0;
int __cdecl Check(void*, int, Params_1917c0*, Params_1917c0*, int);
struct ImpulseVelocityAction_nv_1917c0 {
    int Init(hulkfight::motion::ImpulseVelocityTrack*, int);
};
hulkfight::motion::ImpulseVelocityAction* __cdecl Alloc(int);

int hulkfight::motion::ImpulseVelocityTrack::vfunc_10(int a, int b, int c) {
    int result = Check((void*)c, 0, &TypeA_1917c0, &TypeB_1917c0, 0);
    if (result) {
        hulkfight::motion::ImpulseVelocityAction* p = Alloc(0x24);
        if (p)
            return ((ImpulseVelocityAction_nv_1917c0*)(p))->Init(this, c);
    }
    return 0;
}
