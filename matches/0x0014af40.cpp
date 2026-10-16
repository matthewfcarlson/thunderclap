// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_14af40 {
  public:
    int x;
};
extern Params_14af40 TypeA_14af40;
extern Params_14af40 TypeB_14af40;
int __cdecl Check(void*, int, Params_14af40*, Params_14af40*, int);
class Object_14af40 {
  public:
    int Init(hulkfight::motion::CivilianDetachTrack*, int);
};
Object_14af40* __cdecl Alloc(int);

int hulkfight::motion::CivilianDetachTrack::vfunc_10(int a, int b, int c) {
    int result = Check((void*)c, 0, &TypeA_14af40, &TypeB_14af40, 0);
    if (result) {
        Object_14af40* p = Alloc(0x24);
        if (p)
            return p->Init(this, c);
    }
    return 0;
}
