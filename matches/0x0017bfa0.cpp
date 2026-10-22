// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_17bfa0 {
  public:
    int x;
};
extern Params_17bfa0 TypeA_17bfa0;
extern Params_17bfa0 TypeB_17bfa0;
int __cdecl Check(void*, int, Params_17bfa0*, Params_17bfa0*, int);
struct SnapToGroundAction_17bfa0 {
    int Init(hulkfight::motion::SnapToGroundTrack*, int);
};
hulkfight::motion::SnapToGroundAction* __cdecl Alloc(int);

int hulkfight::motion::SnapToGroundTrack::vfunc_10(int a, int b, int c) {
    int result = Check((void*)c, 0, &TypeA_17bfa0, &TypeB_17bfa0, 0);
    if (result) {
        hulkfight::motion::SnapToGroundAction* p = Alloc(0x24);
        if (p)
            return ((SnapToGroundAction_17bfa0*)(p))->Init(this, c);
    }
    return 0;
}
