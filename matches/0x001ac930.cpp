#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_0041d44c[];
typedef unsigned int u32_1ac930;
void* __cdecl Allocate(unsigned int);
class Initializer_1ac930 {
  public:
    void Init(int);
};
class OffsetInitializer {
  public:
    void Init();
};
class Condition_1ac930 {
  public:
    u32_1ac930 vf;
    char pad4[8];
    int x;
    int y;
    char pad14[4];
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::scenario::Event_CharacterTemplateCondition>::vfunc_5() {
    Condition_1ac930* p = (Condition_1ac930*)Allocate(0x20);
    if (p) {
        ((Initializer_1ac930*)p)->Init(0);
        p->vf = ((hulk_intptr)DAT_0041d44c);
        p->x = 2;
        p->y = 0;
        ((OffsetInitializer*)((char*)p + 0x18))->Init();
        return (void*)(p);
    }
    return (void*)(0);
}
