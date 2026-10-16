// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_157500 {
  public:
    int x;
};
extern Params_157500 TypeA_157500;
extern Params_157500 TypeB_157500;
int __cdecl Check(void*, int, Params_157500*, Params_157500*, int);
class Object_157500 {
  public:
    int Init(hulkfight::motion::HealthTrack*, int);
};
Object_157500* __cdecl Alloc(int);

int hulkfight::motion::HealthTrack::vfunc_10(int a, int b, int c) {
    int result = Check((void*)c, 0, &TypeA_157500, &TypeB_157500, 0);
    if (result) {
        Object_157500* p = Alloc(0x24);
        if (p)
            return p->Init(this, c);
    }
    return 0;
}
