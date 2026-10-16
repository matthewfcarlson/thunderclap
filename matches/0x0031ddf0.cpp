#include "gen/pure3d.h"

class pddiRenderContext_31ddf0 {
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
    virtual void f48();
    virtual void f49();
    virtual void f50();
    virtual void f51(int, unsigned*, unsigned*, unsigned*);
};
struct Rec_31ddf0 {
    char pad[0x5c];
    unsigned x, y, z;
    char tail[0x14];
};

void pure3d::pddiBaseContext::vfunc_51(int i, void* __p1, void* __p2, void* __p3) { unsigned int * a = (unsigned int *)__p1; unsigned int * b = (unsigned int *)__p2; unsigned int * c = (unsigned int *)__p3;

    if (i < 8) {
        *a = (*(Rec_31ddf0 * *)&this->f_50)[i].x;
        *b = (*(Rec_31ddf0 * *)&this->f_50)[i].y;
        *c = (*(Rec_31ddf0 * *)&this->f_50)[i].z;
    } else {
        *c = 0;
        *b = 0;
        *a = 0;
    }
}
