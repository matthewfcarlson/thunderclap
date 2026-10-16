// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_188ce0 {
  public:
    int x;
};
extern Params_188ce0 TypeA_188ce0;
extern Params_188ce0 TypeB_188ce0;
int __cdecl Check(void*, int, Params_188ce0*, Params_188ce0*, int);
class Object_188ce0 {
  public:
    int Init(hulkfight::motion::PropDropTrack*, int);
};
Object_188ce0* __cdecl Alloc(int);

int hulkfight::motion::PropDropTrack::vfunc_10(int a, int b, int c) {
    int result = Check((void*)c, 0, &TypeA_188ce0, &TypeB_188ce0, 0);
    if (result) {
        Object_188ce0* p = Alloc(0x24);
        if (p)
            return p->Init(this, c);
    }
    return 0;
}
