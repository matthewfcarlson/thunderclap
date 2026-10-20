#include "compat/ptr.h"
extern "C" char DAT_003f3390[];
extern "C" char DAT_003f37f4[];
class Ref_1de50 {
  public:
    virtual void A();
    virtual void B();
};
struct Ctor_00232660 {
    Ctor_00232660();
};
class CGrabAction : public Ctor_00232660 {
  public:
    int* vptr;
    char pad04[0x18];
    Ref_1de50* first;
    int m20;
    int m24;
    int m28;
    char pad2c[12];
    char m38;
    char pad39[3];
    Ref_1de50* second;
    CGrabAction(Ref_1de50*, int, Ref_1de50*, int);
};
CGrabAction::CGrabAction(Ref_1de50* a, int b, Ref_1de50* c, int d) : Ctor_00232660() {
    vptr = (int*)((hulk_intptr)DAT_003f3390);
    first = 0;
    if (c)
        c->A();
    if (first)
        first->B();
    first = c;
    vptr = (int*)((hulk_intptr)DAT_003f37f4);
    m24 = d;
    m28 = 0;
    m38 = 0;
    second = 0;
    m20 = b;
    if (a)
        a->A();
    if (second)
        second->B();
    second = a;
}