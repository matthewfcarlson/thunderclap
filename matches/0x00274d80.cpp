#include "compat/ptr.h"
extern "C" char DAT_0042b914[];
extern "C" char DAT_0042b978[];
extern "C" char DAT_0042b9dc[];
class Obj_274d80 {
  public:
    virtual void A();
};
class Elem_274d80 {
  public:
    virtual void A();
    virtual void B();
};
extern void FUN_002705f0();
struct Target_274d80 {
    int vf, p4, p8;
    Obj_274d80* pC;
    Obj_274d80* p10;
    int p14;
    Target_274d80(int, int, Obj_274d80*, int);
};
Target_274d80::Target_274d80(int a, int b, Obj_274d80* c, int d) {
    vf = ((hulk_intptr)DAT_0042b914);
    p4 = 0;
    FUN_002705f0();
    vf = ((hulk_intptr)DAT_0042b9dc);
    p8 = a;
    FUN_002705f0();
    vf = ((hulk_intptr)DAT_0042b978);
    pC = (Obj_274d80*)b;
    p10 = c;
    p14 = d;
    FUN_002705f0();
    p10->A();
    ((Elem_274d80*)((char*)pC + 4))->A();
    ++*(int*)((char*)pC + 0x14);
    ((Elem_274d80*)((char*)pC + 4))->B();
    pC->A();
}