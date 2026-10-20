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
class ObjectManager_1c5b50 : public CAction {
  public:
    ObjectManager_1c5b50* vfunc_2(unsigned char);
};
struct ThisCall_001c5890 {
    void FUN_00019420();
};
extern void thunk_FUN_00267090(ObjectManager_1c5b50*);
ObjectManager_1c5b50* ObjectManager_1c5b50::vfunc_2(unsigned char param_2) {
    ((ThisCall_001c5890*)(this))->FUN_00019420();
    if ((param_2 & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}