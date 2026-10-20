#include "gen/fight.h"

typedef unsigned int size_t;
void* operator new(size_t) throw();
class Base {
  public:
    Base(int) throw();
    virtual void v0();
    virtual void v1();
    virtual void v2();
    char pad[8];
};
class HulkActionLargestCondition_114030 : public Base {
  public:
    HulkActionLargestCondition_114030() throw();
    virtual void v0();
    virtual void v1();
    virtual void v2();
    int a;
    int b;
};
inline HulkActionLargestCondition_114030::HulkActionLargestCondition_114030() throw() : Base(0), a(0), b(0) {}

template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::HulkActionLargestCondition>::vfunc_5() {
    return (void*)(new HulkActionLargestCondition_114030);
}
