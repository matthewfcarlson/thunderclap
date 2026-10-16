// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_19b3c0 {
  public:
    int x;
};
extern Params_19b3c0 TypeA_19b3c0;
extern Params_19b3c0 TypeB_19b3c0;
int __cdecl Check(void*, int, Params_19b3c0*, Params_19b3c0*, int);
class Object_19b3c0 {
  public:
    int Init(hulkfight::motion::FireMissileTrack*, int);
};
Object_19b3c0* __cdecl Alloc(int);

int hulkfight::motion::FireMissileTrack::vfunc_10(int a, int b, int c) {
    int result = Check((void*)c, 0, &TypeA_19b3c0, &TypeB_19b3c0, 0);
    if (result) {
        Object_19b3c0* p = Alloc(0x24);
        if (p)
            return p->Init(this, c);
    }
    return 0;
}
