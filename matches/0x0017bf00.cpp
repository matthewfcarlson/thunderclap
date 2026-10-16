// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_17bf00 {
  public:
    int x;
};
extern Params_17bf00 TypeA_17bf00;
extern Params_17bf00 TypeB_17bf00;
int __cdecl Check(void*, int, Params_17bf00*, Params_17bf00*, int);
class Object_17bf00 {
  public:
    int Init(hulkfight::motion::VisibilityTrack*, int);
};
Object_17bf00* __cdecl Alloc(int);

int hulkfight::motion::VisibilityTrack::vfunc_10(int a, int b, int c) {
    int result = Check((void*)c, 0, &TypeA_17bf00, &TypeB_17bf00, 0);
    if (result) {
        Object_17bf00* p = Alloc(0x24);
        if (p)
            return p->Init(this, c);
    }
    return 0;
}
