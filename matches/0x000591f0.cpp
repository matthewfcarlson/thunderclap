#include "compat/ptr.h"
#include "gen/fight.h"

typedef unsigned int uint;
void* __cdecl Alloc(hulk_uintptr);
class Base_591f0 {
  public:
    Base_591f0(int);
    virtual void a();
    virtual void b();
    virtual void c();
    char pad[0x8];
};
class Inner_591f0 {
  public:
    void Init();
    int x;
};
class Derived : public Base_591f0 {
  public:
    Derived() : Base_591f0(0) {
        m0 = 0;
        m1 = -1;
        ((Inner_591f0*)((char*)this + 0x18))->Init();
    }
    virtual void a();
    virtual void b();
    virtual void c();
    int m0;
    int m1;
    char pad2[4];
};

template <> void* fight::ConditionFactoryTemplate<CSmartPropNameCondition>::vfunc_5() {
    Derived* p = (Derived*)Alloc(0x20);
    if (p) {
        p->Derived::Derived();
        return (void*)(p);
    }
    return (void*)(0);
}
