// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_17b3d0 {
  public:
    int x;
};
extern Params_17b3d0 TypeA_17b3d0;
extern Params_17b3d0 TypeB_17b3d0;
int __cdecl Check(void*, int, Params_17b3d0*, Params_17b3d0*, int);
struct ChargeClearAction_nv_17b3d0 {
    int Init(hulkfight::motion::ChargeClearTrack*, int);
};
hulkfight::motion::ChargeClearAction* __cdecl Alloc(int);

int hulkfight::motion::ChargeClearTrack::vfunc_10(int a, int b, int c) {
    int result = Check((void*)c, 0, &TypeA_17b3d0, &TypeB_17b3d0, 0);
    if (result) {
        hulkfight::motion::ChargeClearAction* p = Alloc(0x24);
        if (p)
            return ((ChargeClearAction_nv_17b3d0*)(p))->Init(this, c);
    }
    return 0;
}
