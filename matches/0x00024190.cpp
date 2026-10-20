#include "compat/ptr.h"
class Obj_24190 {
  public:
    virtual int f0();
    virtual int f1();
    virtual int f2();
    virtual int f3();
    virtual int f4();
    virtual int f5();
    virtual int f6();
    virtual int f7();
    virtual int f8();
    virtual int f9();
    virtual int f10();
    virtual int f11();
    virtual int f12();
    virtual int f13();
    virtual int f14();
    virtual int f15();
    virtual int f16();
    virtual int f17();
    int pad[2];
    int count;
    int items[1];
    int get(int index);
};
class Helper_24190 {
  public:
    int apply(int x);
};
int Obj_24190::get(int index) {
    if (index >= 0 && index < count) {
        Helper_24190* h = (Helper_24190*)*(hulk_intptr*)((hulk_intptr)*(int*)this + 0x44);
        return h->apply(items[index]);
    }
    return 0;
}