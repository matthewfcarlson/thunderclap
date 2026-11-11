// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0017b330..0x0017bc70 (kind game, layer game, confidence low)
// (tree_prelude.h: not needed)


// 0x0017b890 hulkfight::motion::TeleportToLocatorAction::vfunc_2 (79 B): matches/0x0017b890.cpp [isolated: same definition as 0x0017b7f0 in this TU; on include/gen/ and not mergeable]
// sym: ?vfunc_2@TeleportRelativeAction@@QAEPAV1@E@Z
// Same code shape as 0x0017b7f0 (propagated; names are from that function)
#include "gen/fight.h"
extern "C" void __cdecl opdelete(void*);
extern void* const vftable_sym;

class RelObj_17b890 {
  public:
    virtual void f0();
    virtual void Release();
};

class Sub28 {
  public:
    void Fn();
};

class BaseCls_17b890 {
  public:
};

class TeleportRelativeAction {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    TeleportRelativeAction* vfunc_2(unsigned char param);
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();

    char pad[0x18];
    int m1c;
    RelObj_17b890* m20;
    char pad28[4];
    Sub28 m28;
};

TeleportRelativeAction* TeleportRelativeAction::vfunc_2(unsigned char param) {
    char* self = (char*)this;
    *(void**)self = (void*)&vftable_sym;
    RelObj_17b890** pp = (RelObj_17b890**)(self + 0x20);
    RelObj_17b890* p = *pp;
    if (p) {
        p->Release();
        *pp = 0;
    }
    int* q1c = (int*)(self + 0x1c);
    int v = *q1c;
    if (v) {
        *q1c = 0;
    }
    ((Sub28*)(self + 0x28))->Fn();
    ((fight::Action *)(((BaseCls_17b890*)self)))->FUN_002326a0();
    if (param & 1) {
        opdelete(self);
    }
    return (TeleportRelativeAction*)self;
}

