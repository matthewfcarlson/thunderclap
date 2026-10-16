#include "gen/fight.h"

extern "C" char DAT_003f742c[];
extern "C" void* __cdecl Alloc(unsigned int);
class CRageModeCondition_586b0 {
  public:
    void Init(int);
};

template <> void* fight::ConditionFactoryTemplate<CRageModeCondition>::vfunc_5() {
    CRageModeCondition_586b0* p = (CRageModeCondition_586b0*)Alloc(0x10);
    if (p) {
        p->Init(0);
        *(int*)p = ((int)DAT_003f742c);
        *((char*)p + 0xc) = 1;
        return (void*)(p);
    }
    return (void*)((void*)0);
}
