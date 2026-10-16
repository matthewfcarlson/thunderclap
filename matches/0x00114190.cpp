#include "gen/fight.h"

void* operator new(unsigned int);
struct Base_114190 {
    Base_114190(int) throw();
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual Base_114190* f();
    int m4, m8;
};
struct Cond_114190 : Base_114190 {
    int mc, m10;
    Cond_114190() throw() : Base_114190(0) {
        mc = 0;
        m10 = 0;
    }
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual Base_114190* f();
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::ai::HulkActionRecentCondition>::vfunc_5() {
    return (void*)(new Cond_114190);
}
