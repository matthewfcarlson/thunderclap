// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_157060 {
  public:
    int x;
};
extern Params_157060 TypeA_157060;
extern Params_157060 TypeB_157060;
int __cdecl Check(void*, int, Params_157060*, Params_157060*, int);
class Object_157060 {
  public:
    int Init(hulkfight::motion::HitPushbackAddTrack*, int);
};
Object_157060* __cdecl Alloc(int);

int hulkfight::motion::HitPushbackAddTrack::vfunc_10(int a, int b, int c) {
    int result = Check((void*)c, 0, &TypeA_157060, &TypeB_157060, 0);
    if (result) {
        Object_157060* p = Alloc(0x24);
        if (p)
            return p->Init(this, c);
    }
    return 0;
}
