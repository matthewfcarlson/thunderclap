#include "gen/global.h"
#include "decls/data/game/global.h"
// data: globalx = DAT_004de94c

struct V {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8(int);
    virtual void f9(int);
    virtual void f10(int);
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    virtual void f30();
    virtual void f31();
    virtual void f32();
    virtual void f33();
    virtual void f34();
    virtual void f35();
    virtual void f36();
    virtual void f37();
    virtual void f38();
    virtual void f39();
    virtual void f40();
    virtual void f41();
    virtual void f42();
    virtual void f43();
    virtual void f44();
    virtual void f45();
    virtual void f46();
    virtual void f47();
    virtual void f48(int);
};

void FEContainer::vfunc_52(void* __p0, int y) { void * x = (void *)__p0;

    if ((*(V * *)&this->f_48) != x) {
        if ((*(V * *)&this->f_48)) {
            (*(V * *)&this->f_48)->f10(3);
            (*(V * *)&this->f_48)->f9(y);
            (*(V * *)&this->f_04)->f48(2);
        }
        (*(V * *)&this->f_48) = (V*)x;
        if (x) {
            ((V*)x)->f8(y);
            (*(V * *)&this->f_48)->f10(2);
        }
        DAT_004de94c = 0;
    }
}
