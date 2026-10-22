// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_14af40 {
  public:
    int x;
};
extern Params_14af40 TypeA_14af40;
extern Params_14af40 TypeB_14af40;
int __cdecl Check(void*, int, Params_14af40*, Params_14af40*, int);
struct CivilianDetachAction_14af40 {
    int Init(hulkfight::motion::CivilianDetachTrack*, int);
};
hulkfight::motion::CivilianDetachAction* __cdecl Alloc(int);

int hulkfight::motion::CivilianDetachTrack::vfunc_10(int a, int b, int c) {
    int result = Check((void*)c, 0, &TypeA_14af40, &TypeB_14af40, 0);
    if (result) {
        hulkfight::motion::CivilianDetachAction* p = Alloc(0x24);
        if (p)
            return ((CivilianDetachAction_14af40*)(p))->Init(this, c);
    }
    return 0;
}
