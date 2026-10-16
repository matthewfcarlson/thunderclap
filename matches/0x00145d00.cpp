// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_145d00 {
  public:
    int x;
};
extern Params_145d00 TypeA_145d00;
extern Params_145d00 TypeB_145d00;
int __cdecl Check(void*, int, Params_145d00*, Params_145d00*, int);
class Object_145d00 {
  public:
    int Init(hulkfight::motion::MotionTrailStopTrack*, int);
};
Object_145d00* __cdecl Alloc(int);

int hulkfight::motion::MotionTrailStopTrack::vfunc_10(int a, int b, int c) {
    int result = Check((void*)c, 0, &TypeA_145d00, &TypeB_145d00, 0);
    if (result) {
        Object_145d00* p = Alloc(0x24);
        if (p)
            return p->Init(this, c);
    }
    return 0;
}
