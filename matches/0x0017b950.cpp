// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_17b950 {
  public:
    int x;
};
extern Params_17b950 TypeA_17b950;
extern Params_17b950 TypeB_17b950;
int __cdecl Check(void*, int, Params_17b950*, Params_17b950*, int);
class Object_17b950 {
  public:
    int Init(hulkfight::motion::SuckInPropsTrack*, int);
};
Object_17b950* __cdecl Alloc(int);

int hulkfight::motion::SuckInPropsTrack::vfunc_10(int a, int b, int c) {
    int result = Check((void*)c, 0, &TypeA_17b950, &TypeB_17b950, 0);
    if (result) {
        Object_17b950* p = Alloc(0x24);
        if (p)
            return p->Init(this, c);
    }
    return 0;
}
