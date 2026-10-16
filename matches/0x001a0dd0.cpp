#include "gen/fight.h"

extern void* __cdecl FUN_0008d690(unsigned int);
extern int missile_vftable[];
class Prop_1a0dd0 {
  public:
    int m0;
    int m4;
    char pad[4];
    int mC;
    unsigned char m10;
    void Init(int);
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::PropIsMissileCondition>::vfunc_5() {
    Prop_1a0dd0* p = (Prop_1a0dd0*)FUN_0008d690(0x14);
    if (p) {
        p->Init(0);
        p->m0 = (int)missile_vftable;
        p->mC = 0;
        p->m10 = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
