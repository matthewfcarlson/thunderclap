#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_0040fe74[];
extern void* __cdecl FUN_0008d690(unsigned int);
class Init_12a980 {
  public:
    void Start(int);
};
struct Obj_12a980 {
    unsigned int vt;
    int a;
    int b;
    int c;
    int d;
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::TargetVelocityCondition>::vfunc_5() {
    Obj_12a980* p = (Obj_12a980*)FUN_0008d690(0x14);
    if (p) {
        ((Init_12a980*)p)->Start(0);
        p->vt = ((hulk_intptr)DAT_0040fe74);
        p->c = 0;
        p->d = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
