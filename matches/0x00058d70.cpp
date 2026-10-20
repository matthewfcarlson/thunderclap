#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_003f734c[];
extern "C" void* __cdecl Alloc(int);
struct Entity_58d70 {
    void Init();
};
struct Condition_58d70 {
    char pad[0xc];
    int value;
    Entity_58d70 ent;
    void Ctor(int);
};

template <> void* fight::ConditionFactoryTemplate<CCharacterTemplateVariationCondition>::vfunc_5() {
    Condition_58d70* p = (Condition_58d70*)Alloc(0x18);
    if (p) {
        p->Ctor(0);
        *(void**)p = (void*)((hulk_intptr)DAT_003f734c);
        *(int*)((char*)p + 0xc) = 0;
        p->ent.Init();
        return (void*)(p);
    }
    return (void*)(0);
}
