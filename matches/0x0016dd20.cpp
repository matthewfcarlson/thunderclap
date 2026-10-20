#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_00416878[];
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class TargetCharacterTemplateCondition_16dd20 {
  public:
    void Init(int);
    int a;
    int b;
    int c;
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::TargetCharacterTemplateCondition>::vfunc_5() {
    TargetCharacterTemplateCondition_16dd20* p = (TargetCharacterTemplateCondition_16dd20*)FUN_0008d690(0x10);
    if (p) {
        p->Init(0);
        *(void**)p = (void*)((hulk_intptr)DAT_00416878);
        *(int*)((char*)p + 0xc) = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
