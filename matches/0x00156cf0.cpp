// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_156cf0 {
  public:
    int x;
};
extern Params_156cf0 TypeA_156cf0;
extern Params_156cf0 TypeB_156cf0;
int __cdecl Check(void*, int, Params_156cf0*, Params_156cf0*, int);
class Object_156cf0 {
  public:
    int Init(hulkfight::motion::InterruptPriorityTrack*, int);
};
Object_156cf0* __cdecl Alloc(int);

int hulkfight::motion::InterruptPriorityTrack::vfunc_10(int a, int b, int c) {
    int result = Check((void*)c, 0, &TypeA_156cf0, &TypeB_156cf0, 0);
    if (result) {
        Object_156cf0* p = Alloc(0x24);
        if (p)
            return p->Init(this, c);
    }
    return 0;
}
