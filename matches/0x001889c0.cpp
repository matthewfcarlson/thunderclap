// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_1889c0 {
  public:
    int x;
};
extern Params_1889c0 TypeA_1889c0;
extern Params_1889c0 TypeB_1889c0;
int __cdecl Check(void*, int, Params_1889c0*, Params_1889c0*, int);
class Object_1889c0 {
  public:
    int Init(hulkfight::motion::PropAddToMissileCountTrack*, int);
};
Object_1889c0* __cdecl Alloc(int);

int hulkfight::motion::PropAddToMissileCountTrack::vfunc_10(int a, int b, int c) {
    int result = Check((void*)c, 0, &TypeA_1889c0, &TypeB_1889c0, 0);
    if (result) {
        Object_1889c0* p = Alloc(0x24);
        if (p)
            return p->Init(this, c);
    }
    return 0;
}
