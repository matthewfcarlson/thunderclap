// Same code shape as 0x00021840 (propagated; names are from that function)
class IValueChangedReceiver_f1350 {
  public:
    virtual void a();
    virtual void b();
    virtual IValueChangedReceiver_f1350* vfunc_2(unsigned char);
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
};
class FEObject : public IValueChangedReceiver_f1350 {
  public:
    FEObject* vfunc_2(unsigned char);
};
struct ThisCall_000e9030 {
    void FUN_00019420();
};
extern void thunk_FUN_00267090(FEObject*);
FEObject* FEObject::vfunc_2(unsigned char param_2) {
    ((ThisCall_000e9030*)(this))->FUN_00019420();
    if ((param_2 & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}