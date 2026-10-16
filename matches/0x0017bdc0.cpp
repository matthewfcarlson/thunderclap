// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_17bdc0 {
  public:
    int x;
};
extern Params_17bdc0 TypeA_17bdc0;
extern Params_17bdc0 TypeB_17bdc0;
int __cdecl Check(void*, int, Params_17bdc0*, Params_17bdc0*, int);
class Object_17bdc0 {
  public:
    int Init(hulkfight::motion::CriticalMassDrainTrack*, int);
};
Object_17bdc0* __cdecl Alloc(int);

int hulkfight::motion::CriticalMassDrainTrack::vfunc_10(int a, int b, int c) {
    int result = Check((void*)c, 0, &TypeA_17bdc0, &TypeB_17bdc0, 0);
    if (result) {
        Object_17bdc0* p = Alloc(0x24);
        if (p)
            return p->Init(this, c);
    }
    return 0;
}
