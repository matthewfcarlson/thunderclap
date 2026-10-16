// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_17bfa0 {
  public:
    int x;
};
extern Params_17bfa0 TypeA_17bfa0;
extern Params_17bfa0 TypeB_17bfa0;
int __cdecl Check(void*, int, Params_17bfa0*, Params_17bfa0*, int);
class Object_17bfa0 {
  public:
    int Init(hulkfight::motion::SnapToGroundTrack*, int);
};
Object_17bfa0* __cdecl Alloc(int);

int hulkfight::motion::SnapToGroundTrack::vfunc_10(int a, int b, int c) {
    int result = Check((void*)c, 0, &TypeA_17bfa0, &TypeB_17bfa0, 0);
    if (result) {
        Object_17bfa0* p = Alloc(0x24);
        if (p)
            return p->Init(this, c);
    }
    return 0;
}
