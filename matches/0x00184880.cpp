#include "compat/ptr.h"
class Ref_184880 {
  public:
    virtual void Fn();
    virtual void Release();
};
struct Ctor_00232660 {
    Ctor_00232660();
};
extern int vtable_184880;
class BallAndChainShootAction : public Ctor_00232660 {
  public:
    BallAndChainShootAction(int, Ref_184880*);
    int vt;
    char pad04[0x18];
    int mA;
    Ref_184880* mRef;
    int m24;
    int m28;
    int m2c;
    int m30;
    int m34;
    int m38;
    int m3c;
    int m40;
    int m44;
    int m48;
    int m4c;
    int m50;
};
BallAndChainShootAction::BallAndChainShootAction(int a, Ref_184880* b) : Ctor_00232660() {
    vt = (hulk_intptr)&vtable_184880;
    int* q = &mA;
    *q = 0;
    mRef = 0;
    m24 = 0;
    m28 = 0;
    m2c = 0;
    m30 = 0;
    m34 = 0;
    m38 = 0;
    m3c = (int)0xbf800000;
    m40 = 0;
    m44 = 0;
    m48 = 0;
    m4c = 0;
    m50 = 0;
    mA = a;
    if (b)
        b->Fn();
    if (mRef)
        mRef->Release();
    mRef = b;
}