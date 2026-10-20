#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_00414030[];
extern void* __cdecl Allocate(unsigned int);
class CollisionDevastatorCondition_159350 {
  public:
    int vptr;
    char pad[8];
    char flag;
    CollisionDevastatorCondition_159350(int);
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::CollisionDevastatorCondition>::vfunc_5() {
    CollisionDevastatorCondition_159350* p = (CollisionDevastatorCondition_159350*)Allocate(0x10);
    if (p) {
        p->CollisionDevastatorCondition_159350::CollisionDevastatorCondition_159350(0);
        p->vptr = ((hulk_intptr)DAT_00414030);
        p->flag = 1;
        return (void*)(p);
    }
    return (void*)(0);
}
