#include "gen/fight.h"

extern "C" char DAT_004281f0[];
extern "C" void* __cdecl Alloc(unsigned int);
class Obj {
  public:
    int vf;
    int a;
    int b;
    int c;
    Obj(int);
};

template <> void* fight::ConditionFactoryTemplate<fight::MaybeCondition>::vfunc_5() {
    Obj* p = (Obj*)Alloc(0x10);
    if (p) {
        p->Obj::Obj(0);
        p->vf = ((int)DAT_004281f0);
        p->c = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
