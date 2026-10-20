#include "compat/ptr.h"
extern "C" char DAT_00428824[];
class Elem_23c4d0 {
  public:
    void Fn();
};
namespace fight { class Reference {
  public:
    virtual void A();
    virtual void B();
    virtual Reference* vfunc_2(int);
    virtual void D();
    virtual void E();
    virtual void F();
    virtual void G();
    virtual void H();
    virtual void I();
    virtual void J();
    char pad[0x28 - 4];
    void Init();
}; }
extern void __cdecl FUN_00267090(fight::Reference*);
fight::Reference* fight::Reference::vfunc_2(int flag) {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00428824);
    ((Elem_23c4d0*)((char*)this + 0x28))->Fn();
    Init();
    if (flag & 1)
        FUN_00267090(this);
    return this;
}