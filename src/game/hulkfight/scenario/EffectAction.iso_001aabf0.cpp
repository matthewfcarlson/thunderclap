// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001a1ed0..0x001aace0 (kind game, layer game, confidence high), dominant class hulkfight::scenario::EffectAction
// (tree_prelude.h: not needed)
#include "compat/ptr.h"


// 0x001aabf0 fight::ConditionFactoryTemplate<hulkfight::scenario::Event_PropNameCondition>::vfunc_5 (48 B): matches/0x001aabf0.cpp [isolated: conflict: alloc; on include/gen/ and not mergeable]
// sym: ?vfunc_5@?$ConditionFactoryTemplate@VEvent_PropNameCondition@scenario@hulkfight@@@fight@@UAEPAXXZ
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
extern void* __cdecl alloc(hulk_uintptr);
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

