// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_17b700 {
  public:
    int x;
};
extern Params_17b700 TypeA_17b700;
extern Params_17b700 TypeB_17b700;
int __cdecl Check(void*, int, Params_17b700*, Params_17b700*, int);
class Object_17b700 {
  public:
    int Init(hulkfight::motion::TeleportTrack*, int);
};
Object_17b700* __cdecl Alloc(int);

int hulkfight::motion::TeleportTrack::vfunc_10(int a, int b, int c) {
    int result = Check((void*)c, 0, &TypeA_17b700, &TypeB_17b700, 0);
    if (result) {
        Object_17b700* p = Alloc(0x24);
        if (p)
            return p->Init(this, c);
    }
    return 0;
}
