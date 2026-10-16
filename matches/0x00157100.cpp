// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_157100 {
  public:
    int x;
};
extern Params_157100 TypeA_157100;
extern Params_157100 TypeB_157100;
int __cdecl Check(void*, int, Params_157100*, Params_157100*, int);
class Object_157100 {
  public:
    int Init(hulkfight::motion::NoHitPushbackTrack*, int);
};
Object_157100* __cdecl Alloc(int);

int hulkfight::motion::NoHitPushbackTrack::vfunc_10(int a, int b, int c) {
    int result = Check((void*)c, 0, &TypeA_157100, &TypeB_157100, 0);
    if (result) {
        Object_157100* p = Alloc(0x24);
        if (p)
            return p->Init(this, c);
    }
    return 0;
}
