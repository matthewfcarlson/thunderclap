#include "decls/data/engine/content.h"
// data: gThing_2640f0 = DAT_00527c58

class Inner_2640f0 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual bool f20();
    virtual void f21();
};
class Manager_2640f0 {
  public:
    void update();
};
extern int getThing();
class Target_2640f0 {
  public:
    char pad0[8];
    Inner_2640f0* obj;
    char padc[1];
    bool flag;
    char pad_e[0x36];
    int result;
    void run();
};
void Target_2640f0::run() {
    if (obj) {
        if (flag) {
            obj->f21();
            return;
        }
        while (!obj->f20()) {
            (*(Manager_2640f0**)&DAT_00527c58)->update();
            result = getThing();
        }
    }
}