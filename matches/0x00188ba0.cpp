// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_188ba0 {
  public:
    int x;
};
extern Params_188ba0 TypeA_188ba0;
extern Params_188ba0 TypeB_188ba0;
int __cdecl Check(void*, int, Params_188ba0*, Params_188ba0*, int);
class Object_188ba0 {
  public:
    int Init(hulkfight::motion::PropSetStateByNameTrack*, int);
};
Object_188ba0* __cdecl Alloc(int);

int hulkfight::motion::PropSetStateByNameTrack::vfunc_10(int a, int b, int c) {
    int result = Check((void*)c, 0, &TypeA_188ba0, &TypeB_188ba0, 0);
    if (result) {
        Object_188ba0* p = Alloc(0x24);
        if (p)
            return p->Init(this, c);
    }
    return 0;
}
