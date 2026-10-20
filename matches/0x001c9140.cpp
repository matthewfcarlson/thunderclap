// Same code shape as 0x00021840 (propagated; names are from that function)
class CAction {
  public:
    virtual void a();
    virtual void b();
    virtual CAction* vfunc_2(unsigned char);
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g();
    virtual void h();
};
class World_1c9140 : public CAction {
  public:
    World_1c9140* vfunc_2(unsigned char);
};
struct ThisCall_001c86e0 {
    void FUN_00019420();
};
extern void thunk_FUN_00267090(World_1c9140*);
World_1c9140* World_1c9140::vfunc_2(unsigned char param_2) {
    ((ThisCall_001c86e0*)(this))->FUN_00019420();
    if ((param_2 & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}