// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_188ec0 {
  public:
    int x;
};
extern Params_188ec0 TypeA_188ec0;
extern Params_188ec0 TypeB_188ec0;
int __cdecl Check(void*, int, Params_188ec0*, Params_188ec0*, int);
class Object_188ec0 {
  public:
    int Init(hulkfight::motion::PropDestroyTrack*, int);
};
Object_188ec0* __cdecl Alloc(int);

int hulkfight::motion::PropDestroyTrack::vfunc_10(int a, int b, int c) {
    int result = Check((void*)c, 0, &TypeA_188ec0, &TypeB_188ec0, 0);
    if (result) {
        Object_188ec0* p = Alloc(0x24);
        if (p)
            return p->Init(this, c);
    }
    return 0;
}
