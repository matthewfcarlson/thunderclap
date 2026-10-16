// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_19b9b0 {
  public:
    int x;
};
extern Params_19b9b0 TypeA_19b9b0;
extern Params_19b9b0 TypeB_19b9b0;
int __cdecl Check(void*, int, Params_19b9b0*, Params_19b9b0*, int);
class Object_19b9b0 {
  public:
    int Init(hulkfight::motion::FireGroundShockwaveTrack*, int);
};
Object_19b9b0* __cdecl Alloc(int);

int hulkfight::motion::FireGroundShockwaveTrack::vfunc_10(int a, int b, int c) {
    int result = Check((void*)c, 0, &TypeA_19b9b0, &TypeB_19b9b0, 0);
    if (result) {
        Object_19b9b0* p = Alloc(0x24);
        if (p)
            return p->Init(this, c);
    }
    return 0;
}
