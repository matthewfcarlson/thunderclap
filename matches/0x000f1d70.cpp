extern "C" void _ReadWriteBarrier();
class Ref {
  public:
    virtual void a();
    virtual void Release();
};
class FEScreenBase {
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
    virtual void w();
    virtual void x();
    virtual void y();
    virtual void z();
    virtual void aa();
    virtual void ab();
    virtual void ac();
    virtual void ad();
    virtual void ae();
    virtual void af();
    virtual void ag();
    virtual void ah();
    virtual void ai();
    virtual void aj();
    virtual void ak();
    virtual void al();
    virtual void am();
    virtual void an();
    virtual void ao();
    virtual void ap();
    virtual void aq();
    virtual void ar();
    virtual void as();
    virtual void at();
    virtual void au();
    virtual void av();
    virtual void aw();
    virtual void ax();
    virtual void ay();
    virtual void az();
    virtual void ba();
    virtual void bb();
    virtual void bc();
    virtual void bd();
    virtual void be();
    virtual void bf();
};
class FEMenuBase : public FEScreenBase {
  public:
    char pad[0x98c];
    Ref* field;
    virtual FEMenuBase* vfunc_0(unsigned char);
    void helper();
};
void thunk_FUN_00267090(FEMenuBase*);
FEMenuBase* FEMenuBase::vfunc_0(unsigned char p) {
    *(void**)this = (void*)0x40c924;
    _ReadWriteBarrier();
    if (field) {
        field->Release();
        field = 0;
    }
    helper();
    if (p & 1)
        thunk_FUN_00267090(this);
    return this;
}