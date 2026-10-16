// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_129600 {
  public:
    int x;
};
extern Params_129600 TypeA_129600;
extern Params_129600 TypeB_129600;
int __cdecl Check(void*, int, Params_129600*, Params_129600*, int);
class Object_129600 {
  public:
    int Init(hulkfight::ai::ClearProjectileDistanceTrack*, int);
};
Object_129600* __cdecl Alloc(int);

int hulkfight::ai::ClearProjectileDistanceTrack::vfunc_10(int a, int b, int c) {
    int result = Check((void*)c, 0, &TypeA_129600, &TypeB_129600, 0);
    if (result) {
        Object_129600* p = Alloc(0x24);
        if (p)
            return p->Init(this, c);
    }
    return 0;
}
