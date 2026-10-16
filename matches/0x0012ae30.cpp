#include "gen/fight.h"

extern "C" char DAT_0040ff54[];
typedef unsigned char u8;
class CanSeeTargetCondition_12ae30 {
  public:
    int vt;
    char pad[8];
    u8 a;
    u8 b;
    void Init(int);
};
extern void* __cdecl alloc(unsigned int);

template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::CanSeeTargetCondition>::vfunc_5() {
    CanSeeTargetCondition_12ae30* p = (CanSeeTargetCondition_12ae30*)alloc(16);
    if (p) {
        p->Init(0);
        p->a = 1;
        p->b = 1;
        p->vt = ((int)DAT_0040ff54);
        return (void*)(p);
    }
    return (void*)(0);
}
