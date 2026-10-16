// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_119d10 {
  public:
    int x;
};
extern Params_119d10 TypeA_119d10;
extern Params_119d10 TypeB_119d10;
int __cdecl Check(void*, int, Params_119d10*, Params_119d10*, int);
class Object_119d10 {
  public:
    int Init(hulkfight::ai::MotionStopTrack*, int);
};
Object_119d10* __cdecl Alloc(int);

int hulkfight::ai::MotionStopTrack::vfunc_10(int a, int b, int c) {
    int result = Check((void*)c, 0, &TypeA_119d10, &TypeB_119d10, 0);
    if (result) {
        Object_119d10* p = Alloc(0x24);
        if (p)
            return p->Init(this, c);
    }
    return 0;
}
