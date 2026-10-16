#include "gen/fight.h"

extern "C" char DAT_0040db64[];
class Condition_1147b0 {
  public:
    int vt;
    char pad[8];
    int m;
    void Init(int);
};
extern void* __cdecl Alloc(unsigned int);

template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::FightingOtherNPCCondition>::vfunc_5() {
    Condition_1147b0* p = (Condition_1147b0*)Alloc(0x10);
    if (p) {
        p->Init(0);
        p->vt = ((int)DAT_0040db64);
        p->m = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
