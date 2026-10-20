#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_003f7328[];
extern "C" void* __cdecl Alloc(unsigned int);
struct Obj_58cc0 {
    void Init(int);
};
struct Sub_58cc0 {
    void Init();
};
struct CCharacterTemplateCondition_58cc0 {
    char pad[24];
};

template <> void* fight::ConditionFactoryTemplate<CCharacterTemplateCondition>::vfunc_5() {
    CCharacterTemplateCondition_58cc0* p = (CCharacterTemplateCondition_58cc0*)Alloc(0x18);
    if (p) {
        ((Obj_58cc0*)p)->Init(0);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_003f7328);
        *(unsigned int*)((char*)p + 0xc) = 0;
        ((Sub_58cc0*)((char*)p + 0x10))->Init();
        return (void*)(p);
    }
    return (void*)(0);
}
