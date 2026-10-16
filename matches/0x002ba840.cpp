#include "gen/pure3d.h"

struct V {
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
    virtual void f16(int);
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23(int, void*);
};
struct Inner_2ba840 {
    V* v;
    char pad[0x7c];
    unsigned int x;
};
struct Obj_2ba840 {
    Inner_2ba840* p;
};
struct BillboardObject_nv_2ba840 {
    void helper(unsigned int, unsigned int);
};
extern V** gObj_2ba840;

void pure3d::BillboardObject::vfunc_8(int __p0, int __p1) { unsigned int a = (unsigned int)__p0; unsigned int b = (unsigned int)__p1;

    gObj_2ba840[0]->f23(0, (char*)(*(Obj_2ba840 * *)&this->f_48)->p + 0x40);
    (*(Obj_2ba840 * *)&this->f_48)->p->x = this->f_58;
    ((BillboardObject_nv_2ba840*)this)->helper(a, b);
    (*(Obj_2ba840 * *)&this->f_48)->p->x = 0x3f800000;
    gObj_2ba840[0]->f16(0);
}
