#include "compat/ptr.h"
#include "gen/fight.h"

extern "C" char DAT_0041c5d0[];
class Base_1aabf0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
};
extern void* __cdecl alloc(unsigned int);
class Obj_1aabf0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    void init(int);
};
class Sub_1aabf0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    void init();
};

template <> void* fight::ConditionFactoryTemplate<hulkfight::scenario::Event_PropNameCondition>::vfunc_5() {
    Obj_1aabf0* p = (Obj_1aabf0*)alloc(0x18);
    if (p) {
        p->init(0);
        *((hulk_intptr*)p) = ((hulk_intptr)DAT_0041c5d0);
        ((Sub_1aabf0*)((char*)p + 0x10))->init();
        return (void*)(p);
    }
    return (void*)(0);
}
