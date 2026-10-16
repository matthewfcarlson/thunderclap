// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_1887d0 {
  public:
    int x;
};
extern Params_1887d0 TypeA_1887d0;
extern Params_1887d0 TypeB_1887d0;
int __cdecl Check(void*, int, Params_1887d0*, Params_1887d0*, int);
class Object_1887d0 {
  public:
    int Init(hulkfight::motion::PropActorToPropTrack*, int);
};
Object_1887d0* __cdecl Alloc(int);

int hulkfight::motion::PropActorToPropTrack::vfunc_10(int a, int b, int c) {
    int result = Check((void*)c, 0, &TypeA_1887d0, &TypeB_1887d0, 0);
    if (result) {
        Object_1887d0* p = Alloc(0x24);
        if (p)
            return p->Init(this, c);
    }
    return 0;
}
