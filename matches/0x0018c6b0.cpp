#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_0041920c[];
extern void* __cdecl FUN_0008d690(hulk_uintptr);
class Sub_18c6b0 {
  public:
    void Init();
};
class PropStateByNameCondition_18c6b0 {
  public:
    void Init(int);
    char vptr[4];
    char pad04[8];
    int x;
    int y;
    char pad14[4];
    Sub_18c6b0 sub;
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::PropStateByNameCondition>::vfunc_5() {
    PropStateByNameCondition_18c6b0* p = (PropStateByNameCondition_18c6b0*)FUN_0008d690(0x20);
    if (p) {
        p->Init(0);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_0041920c);
        p->x = -1;
        p->y = 0;
        p->sub.Init();
        return (void*)(p);
    }
    return (void*)(0);
}
