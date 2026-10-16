// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_12ca10 {
  public:
    int x;
};
extern Params_12ca10 TypeA_12ca10;
extern Params_12ca10 TypeB_12ca10;
int __cdecl Check(void*, int, Params_12ca10*, Params_12ca10*, int);
class Object_12ca10 {
  public:
    int Init(hulkfight::ai::ThreatDodgeTrack*, int);
};
Object_12ca10* __cdecl Alloc(int);

int hulkfight::ai::ThreatDodgeTrack::vfunc_10(int a, int b, int c) {
    int result = Check((void*)c, 0, &TypeA_12ca10, &TypeB_12ca10, 0);
    if (result) {
        Object_12ca10* p = Alloc(0x24);
        if (p)
            return p->Init(this, c);
    }
    return 0;
}
