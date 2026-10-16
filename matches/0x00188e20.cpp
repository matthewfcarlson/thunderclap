// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_188e20 {
  public:
    int x;
};
extern Params_188e20 TypeA_188e20;
extern Params_188e20 TypeB_188e20;
int __cdecl Check(void*, int, Params_188e20*, Params_188e20*, int);
class Object_188e20 {
  public:
    int Init(hulkfight::motion::GrapplePropDamageTrack*, int);
};
Object_188e20* __cdecl Alloc(int);

int hulkfight::motion::GrapplePropDamageTrack::vfunc_10(int a, int b, int c) {
    int result = Check((void*)c, 0, &TypeA_188e20, &TypeB_188e20, 0);
    if (result) {
        Object_188e20* p = Alloc(0x24);
        if (p)
            return p->Init(this, c);
    }
    return 0;
}
