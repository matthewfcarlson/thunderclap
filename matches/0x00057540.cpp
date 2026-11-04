#include "compat/ptr.h"
#include "gen/fight.h"

class CCharacterSizeCondition_57540 {
  public:
    hulk_intptr x;
    int a;
    int b;
    int c;
    int d;
    void Init(int);
};
extern "C" void* FUN_0008d690(unsigned int);
extern int g_vtable_57540[];

template <> void* fight::ConditionFactoryTemplate<CCharacterSizeCondition>::vfunc_5() {
    CCharacterSizeCondition_57540* p = (CCharacterSizeCondition_57540*)FUN_0008d690((int)sizeof(CCharacterSizeCondition_57540));
    if (p) {
        p->Init(0);
        p->x = (hulk_intptr)g_vtable_57540;
        p->c = 0;
        p->d = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
