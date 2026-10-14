// Same code shape as 0x002345b0 (propagated; names are from that function)
class Ref_236d60 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void Release(int);
};
class Parent_236d60 {
  public:
    virtual void p();
};
void __fastcall FUN_00234210(void* self);
class Condition : public Parent_236d60 {
  public:
    virtual ~Condition();
    Ref_236d60* mRef;
};
Condition::~Condition() {
    if (mRef)
        mRef->Release(1);
    mRef = 0;
    FUN_00234210(this);
}
