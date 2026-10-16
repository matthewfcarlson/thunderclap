#include "gen/fight.h"

extern "C" char DAT_003f8628[];
typedef unsigned int u32_52540;
extern "C" void* __cdecl thunk_FUN_0008d690(unsigned int);
class Helper_52540 {
  public:
    void Init();
};
class Init2 {
  public:
    void Init(unsigned int);
};

template <> void* fight::ConditionFactoryCasterTemplate<CIsGrappledCondition>::vfunc_1(void* __p0) { unsigned int arg = (unsigned int)__p0;

    void* p = thunk_FUN_0008d690(0x10);
    if (p) {
        ((Helper_52540*)p)->Init();
        *(u32_52540*)p = ((int)DAT_003f8628);
        ((Init2*)((char*)p + 8))->Init(arg);
        return (void*)(p);
    }
    return (void*)(0);
}
