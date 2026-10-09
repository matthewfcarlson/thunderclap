class SeqAction {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
};
extern void __cdecl FUN_00247550(void*, void*);
class SeqActionCrossFade : public SeqAction {
  public:
    virtual SeqActionCrossFade* vfunc_0(int);
};
SeqActionCrossFade* SeqActionCrossFade::vfunc_0(int flag) {
    *(void**)this = (void*)0x4298fc;
    if (flag & 1)
        FUN_00247550((void*)0x4e74c0, this);
    return this;
}