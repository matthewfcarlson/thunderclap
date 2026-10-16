#include "gen/fight.h"

extern "C" char DAT_003f85c4[];
class CGrappleFightNodeParentCondition_52390 {
  public:
    virtual void A();
    virtual void B();
    virtual void C();
    virtual void D();
    virtual void E();
    virtual void F();
    void Init();
};
extern "C" void* FUN_0008d690(unsigned int);

template <> void* fight::ConditionFactoryTemplate<CGrappleFightNodeParentCondition>::vfunc_5() {
    CGrappleFightNodeParentCondition_52390* p = (CGrappleFightNodeParentCondition_52390*)FUN_0008d690(0x20);
    if (p) {
        p->Init();
        *(int*)p = ((int)DAT_003f85c4);
        return (void*)(p);
    }
    return (void*)(0);
}
