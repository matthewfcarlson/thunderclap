// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_144a50 {
  public:
    int x;
};
extern Params_144a50 TypeA_144a50;
extern Params_144a50 TypeB_144a50;
int __cdecl Check(void*, int, Params_144a50*, Params_144a50*, int);
class Object_144a50 {
  public:
    int Init(hulkfight::motion::WorldConeDamageTrack*, int);
};
Object_144a50* __cdecl Alloc(int);

int hulkfight::motion::WorldConeDamageTrack::vfunc_10(int a, int b, int c) {
    int result = Check((void*)c, 0, &TypeA_144a50, &TypeB_144a50, 0);
    if (result) {
        Object_144a50* p = Alloc(0x24);
        if (p)
            return p->Init(this, c);
    }
    return 0;
}
