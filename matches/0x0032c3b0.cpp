extern unsigned int gState, gState1, gState2;
extern void __stdcall SetTextureState(int, int);
class Device {
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
class Shader {
  public:
    char pad0[0x10];
    DevVirtual* v;
    Device* dev;
    void vfunc_13();
};
void Shader::vfunc_13() {
    Device* d = dev;
    if (d->stateE4 != 1) {
        d->stateE4 = 1;
        gState |= 0x800;
        gState1 = 1;
    }
    d = dev;
    if (d->texCoord != 1) {
        d->texCoord = 1;
        SetTextureState(1, 1);
    }
    d = dev;
    if (d->stateF8 != 0) {
        d->stateF8 = 0;
        gState |= 0x400;
        gState2 = 0;
    }
    v->q(2);
}