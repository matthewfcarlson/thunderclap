#include "gen/pure3d.h"

class Obj_298c00 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual char Check();
};
class Obj22 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
    virtual void i();
    virtual void j();
    virtual void k();
    virtual void l();
    virtual void m();
    virtual void n();
    virtual void o();
    virtual void p();
    virtual void q();
    virtual void r();
    virtual void s();
    virtual void t();
    virtual void u();
    virtual void v();
    virtual char Check();
};
struct First_298c00 {
    char pad20[0x20];
    unsigned char count;
    char pad[0xf];
    unsigned char* ids;
    char pad2[8];
    Obj_298c00** objs;
};
struct Second_298c00 {
    char pad8[8];
    unsigned char count;
    char pad[0xf];
    unsigned char* ids;
    char pad2[8];
    Obj22** objs;
};

char pure3d::CompositeDrawable::vfunc_7() {
    unsigned char i = 0;
    if (!(*(Second_298c00 * *)&this->f_48)) {
        unsigned char n = (*(First_298c00 * *)&this->f_44)->count;
        while (i < n) {
            Obj_298c00* o = (*(First_298c00 * *)&this->f_44)->objs[(*(First_298c00 * *)&this->f_44)->ids[i] * 3 + 2];
            if (!o->Check())
                return 0;
            ++i;
        }
        if ((*(Obj22 * *)&this->f_4c) && !(*(Obj22 * *)&this->f_4c)->Check())
            return 0;
        if ((*(Obj22 * *)&this->f_50) && !(*(Obj22 * *)&this->f_50)->Check())
            return 0;
    } else {
        unsigned char n = (*(Second_298c00 * *)&this->f_48)->count;
        while (i < n) {
            Obj22* o = (*(Second_298c00 * *)&this->f_48)->objs[(*(Second_298c00 * *)&this->f_48)->ids[i]];
            if (!o->Check())
                return 0;
            ++i;
        }
    }
    return 1;
}
