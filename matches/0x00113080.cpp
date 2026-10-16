// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_113080 {
  public:
    int x;
};
extern Params_113080 TypeA_113080;
extern Params_113080 TypeB_113080;
int __cdecl Check(void*, int, Params_113080*, Params_113080*, int);
class Object_113080 {
  public:
    int Init(hulkfight::ai::ButtonTrack*, int);
};
Object_113080* __cdecl Alloc(int);

int hulkfight::ai::ButtonTrack::vfunc_10(int a, int b, int c) {
    int result = Check((void*)c, 0, &TypeA_113080, &TypeB_113080, 0);
    if (result) {
        Object_113080* p = Alloc(0x24);
        if (p)
            return p->Init(this, c);
    }
    return 0;
}
