#include "gen/pure3d.h"

extern unsigned int gState_32c3b0, gState1, gState2;
extern void __stdcall SetTextureState(int, int);
class Device_32c3b0 {
  public:
    char pad0[0x1c];
    int texCoord;
    char pad1[0xc4];
    int stateE4;
    char pad2[0x10];
    int stateF8;
};
class DevVirtual {
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
    virtual void q(int);
};

void pure3d::d3dReflShader::vfunc_13() {
    Device_32c3b0* d = (*(Device_32c3b0 * *)&this->f_14);
    if (d->stateE4 != 1) {
        d->stateE4 = 1;
        gState_32c3b0 |= 0x800;
        gState1 = 1;
    }
    d = (*(Device_32c3b0 * *)&this->f_14);
    if (d->texCoord != 1) {
        d->texCoord = 1;
        SetTextureState(1, 1);
    }
    d = (*(Device_32c3b0 * *)&this->f_14);
    if (d->stateF8 != 0) {
        d->stateF8 = 0;
        gState_32c3b0 |= 0x400;
        gState2 = 0;
    }
    (*(DevVirtual * *)&this->f_10)->q(2);
}
