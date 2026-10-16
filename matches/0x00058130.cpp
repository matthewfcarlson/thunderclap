#include "gen/fight.h"

extern "C" char DAT_003f6f5c[];
class GroundCondition {
  public:
    void Init(int);
};
extern "C" void* Alloc(unsigned int);

template <> void* fight::ConditionFactoryTemplate<CGroundDistanceCondition>::vfunc_5() {
    GroundCondition* p = (GroundCondition*)Alloc(0x14);
    if (p) {
        p->Init(0);
        *(unsigned int*)p = ((int)DAT_003f6f5c);
        *(unsigned int*)((char*)p + 0xc) = 0;
        *(unsigned int*)((char*)p + 0x10) = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
