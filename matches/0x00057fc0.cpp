#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_003f72e0[];
class AllocObj_57fc0 {
  public:
    void Init(int);
};
extern "C" void* __cdecl FUN_0008d690(unsigned int);

template <> void* fight::ConditionFactoryTemplate<CGrappleSizeCondition>::vfunc_5() {
    AllocObj_57fc0* p = (AllocObj_57fc0*)FUN_0008d690(0x14);
    if (p) {
        p->Init(0);
        *(void**)p = (void*)((hulk_intptr)DAT_003f72e0);
        *(int*)((char*)p + 0xc) = 0;
        *(int*)((char*)p + 0x10) = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
