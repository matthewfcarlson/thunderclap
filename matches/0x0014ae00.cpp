// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_14ae00 {
  public:
    int x;
};
extern Params_14ae00 TypeA_14ae00;
extern Params_14ae00 TypeB_14ae00;
int __cdecl Check(void*, int, Params_14ae00*, Params_14ae00*, int);
class Object_14ae00 {
  public:
    int Init(hulkfight::motion::CivilianThrowTrack*, int);
};
Object_14ae00* __cdecl Alloc(int);

int hulkfight::motion::CivilianThrowTrack::vfunc_10(int a, int b, int c) {
    int result = Check((void*)c, 0, &TypeA_14ae00, &TypeB_14ae00, 0);
    if (result) {
        Object_14ae00* p = Alloc(0x24);
        if (p)
            return p->Init(this, c);
    }
    return 0;
}
