#include "gen/fight.h"

class GrappleHealthCondition_16dc70 {
  public:
    GrappleHealthCondition_16dc70();
    void Init(int x);
    virtual void f0() {}
    virtual void f1() {}
    virtual void f2() {}
    virtual void f3() {}
    virtual void f4() {}
    virtual void f5() {}
    int m4;
    int m8;
    int m12;
    int m16;
    int m20;
};

GrappleHealthCondition_16dc70::GrappleHealthCondition_16dc70() {
    m12 = 0;
    m16 = 0;
    m20 = 0;
}

void* Alloc(unsigned int);

template <> void* fight::ConditionFactoryTemplate<hulkfight::motion::GrappleHealthCondition>::vfunc_5() {
    GrappleHealthCondition_16dc70* p = (GrappleHealthCondition_16dc70*)Alloc(0x18);
    if (p) {
        p->Init(0);
        p->GrappleHealthCondition_16dc70::GrappleHealthCondition_16dc70();
        return (void*)(p);
    }
    return (void*)(0);
}
