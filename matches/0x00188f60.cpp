// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_188f60 {
  public:
    int x;
};
extern Params_188f60 TypeA_188f60;
extern Params_188f60 TypeB_188f60;
int __cdecl Check(void*, int, Params_188f60*, Params_188f60*, int);
struct PropThrowAction_nv_188f60 {
    int Init(hulkfight::motion::PropThrowTrack*, int);
};
hulkfight::motion::PropThrowAction* __cdecl Alloc(int);

int hulkfight::motion::PropThrowTrack::vfunc_10(int a, int b, int c) {
    int result = Check((void*)c, 0, &TypeA_188f60, &TypeB_188f60, 0);
    if (result) {
        hulkfight::motion::PropThrowAction* p = Alloc(0x24);
        if (p)
            return ((PropThrowAction_nv_188f60*)(p))->Init(this, c);
    }
    return 0;
}
