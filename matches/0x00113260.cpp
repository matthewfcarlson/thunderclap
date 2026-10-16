// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_113260 {
  public:
    int x;
};
extern Params_113260 TypeA_113260;
extern Params_113260 TypeB_113260;
int __cdecl Check(void*, int, Params_113260*, Params_113260*, int);
class Object_113260 {
  public:
    int Init(hulkfight::ai::TokenTrack*, int);
};
Object_113260* __cdecl Alloc(int);

int hulkfight::ai::TokenTrack::vfunc_10(int a, int b, int c) {
    int result = Check((void*)c, 0, &TypeA_113260, &TypeB_113260, 0);
    if (result) {
        Object_113260* p = Alloc(0x24);
        if (p)
            return p->Init(this, c);
    }
    return 0;
}
