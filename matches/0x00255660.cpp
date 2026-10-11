extern "C" char DAT_004298fc[];
extern "C" char DAT_004e74c0[];
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
    *(void**)this = (void*)((int)DAT_004298fc);
    if (flag & 1)
        FUN_00247550((void*)((int)DAT_004e74c0), this);
    return this;
}