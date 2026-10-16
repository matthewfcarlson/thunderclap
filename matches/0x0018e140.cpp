// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_18e140 {
  public:
    int x;
};
extern Params_18e140 TypeA_18e140;
extern Params_18e140 TypeB_18e140;
int __cdecl Check(void*, int, Params_18e140*, Params_18e140*, int);
class Object_18e140 {
  public:
    int Init(hulkfight::motion::VarAssignTrack*, int);
};
Object_18e140* __cdecl Alloc(int);

int hulkfight::motion::VarAssignTrack::vfunc_10(int a, int b, int c) {
    int result = Check((void*)c, 0, &TypeA_18e140, &TypeB_18e140, 0);
    if (result) {
        Object_18e140* p = Alloc(0x24);
        if (p)
            return p->Init(this, c);
    }
    return 0;
}
