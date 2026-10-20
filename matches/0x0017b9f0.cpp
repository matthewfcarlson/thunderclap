// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_17b9f0 {
  public:
    int x;
};
extern Params_17b9f0 TypeA_17b9f0;
extern Params_17b9f0 TypeB_17b9f0;
int __cdecl Check(void*, int, Params_17b9f0*, Params_17b9f0*, int);
struct TargetIconDistanceAction_nv_17b9f0 {
    int Init(hulkfight::motion::TargetIconDistanceTrack*, int);
};
hulkfight::motion::TargetIconDistanceAction* __cdecl Alloc(int);

int hulkfight::motion::TargetIconDistanceTrack::vfunc_10(int a, int b, int c) {
    int result = Check((void*)c, 0, &TypeA_17b9f0, &TypeB_17b9f0, 0);
    if (result) {
        hulkfight::motion::TargetIconDistanceAction* p = Alloc(0x24);
        if (p)
            return ((TargetIconDistanceAction_nv_17b9f0*)(p))->Init(this, c);
    }
    return 0;
}
