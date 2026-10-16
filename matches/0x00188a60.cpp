// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_188a60 {
  public:
    int x;
};
extern Params_188a60 TypeA_188a60;
extern Params_188a60 TypeB_188a60;
int __cdecl Check(void*, int, Params_188a60*, Params_188a60*, int);
class Object_188a60 {
  public:
    int Init(hulkfight::motion::PropAddToCollisionTrack*, int);
};
Object_188a60* __cdecl Alloc(int);

int hulkfight::motion::PropAddToCollisionTrack::vfunc_10(int a, int b, int c) {
    int result = Check((void*)c, 0, &TypeA_188a60, &TypeB_188a60, 0);
    if (result) {
        Object_188a60* p = Alloc(0x24);
        if (p)
            return p->Init(this, c);
    }
    return 0;
}
