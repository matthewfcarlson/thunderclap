// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_188d80 {
  public:
    int x;
};
extern Params_188d80 TypeA_188d80;
extern Params_188d80 TypeB_188d80;
int __cdecl Check(void*, int, Params_188d80*, Params_188d80*, int);
class Object_188d80 {
  public:
    int Init(hulkfight::motion::PropDamageTrack*, int);
};
Object_188d80* __cdecl Alloc(int);

int hulkfight::motion::PropDamageTrack::vfunc_10(int a, int b, int c) {
    int result = Check((void*)c, 0, &TypeA_188d80, &TypeB_188d80, 0);
    if (result) {
        Object_188d80* p = Alloc(0x24);
        if (p)
            return p->Init(this, c);
    }
    return 0;
}
