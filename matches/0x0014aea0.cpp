// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_14aea0 {
  public:
    int x;
};
extern Params_14aea0 TypeA_14aea0;
extern Params_14aea0 TypeB_14aea0;
int __cdecl Check(void*, int, Params_14aea0*, Params_14aea0*, int);
struct CivilianAttachAction_nv_14aea0 {
    int Init(hulkfight::motion::CivilianAttachTrack*, int);
};
hulkfight::motion::CivilianAttachAction* __cdecl Alloc(int);

int hulkfight::motion::CivilianAttachTrack::vfunc_10(int a, int b, int c) {
    int result = Check((void*)c, 0, &TypeA_14aea0, &TypeB_14aea0, 0);
    if (result) {
        hulkfight::motion::CivilianAttachAction* p = Alloc(0x24);
        if (p)
            return ((CivilianAttachAction_nv_14aea0*)(p))->Init(this, c);
    }
    return 0;
}
