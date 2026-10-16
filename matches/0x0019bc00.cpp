// Same code shape as 0x0010bd40 (propagated; names are from that function)
#include "gen/hulkfight.h"

class Params_19bc00 {
  public:
    int x;
};
extern Params_19bc00 TypeA_19bc00;
extern Params_19bc00 TypeB_19bc00;
int __cdecl Check(void*, int, Params_19bc00*, Params_19bc00*, int);
class Object_19bc00 {
  public:
    int Init(hulkfight::motion::MissilePunchTrack*, int);
};
Object_19bc00* __cdecl Alloc(int);

int hulkfight::motion::MissilePunchTrack::vfunc_10(int a, int b, int c) {
    int result = Check((void*)c, 0, &TypeA_19bc00, &TypeB_19bc00, 0);
    if (result) {
        Object_19bc00* p = Alloc(0x24);
        if (p)
            return p->Init(this, c);
    }
    return 0;
}
