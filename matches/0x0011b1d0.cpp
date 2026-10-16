#include "gen/fight.h"

typedef unsigned int size_t;
void* operator new(size_t);
extern "C" void _ReadWriteBarrier();
class BaseCondition {
  public:
    virtual void v0();
    char pad[8];
    unsigned char a, b, c, d, e, f;
    BaseCondition(int) throw();
};
class IntermediateCondition : public BaseCondition {
  public:
    IntermediateCondition() throw() : BaseCondition(0) {
        a = 1;
        b = 1;
        c = 0;
        d = 0;
        e = 0;
        f = 0;
    }
};
class HasGroundPointExtendedCondition_11b1d0 : public IntermediateCondition {
  public:
    float x, y;
    int p, q, r;
    HasGroundPointExtendedCondition_11b1d0() throw() : IntermediateCondition() {
        _ReadWriteBarrier();
        x = 1.0f;
        y = 2.0f;
        _ReadWriteBarrier();
        p = 0;
        q = 0;
        r = 0;
    }
    virtual void v0();
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::HasGroundPointExtendedCondition>::vfunc_5() {
    return (void*)(new HasGroundPointExtendedCondition_11b1d0);
}
