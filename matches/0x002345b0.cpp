class Ref_2345b0 {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void Release(int);
};
class Parent_2345b0 {
  public:
    virtual void p();
};
void __fastcall FUN_00234210(void* self);
class Condition : public Parent_2345b0 {
  public:
    virtual ~Condition();
    Ref_2345b0* mRef;
};
Condition::~Condition() {
    if (mRef)
        mRef->Release(1);
    mRef = 0;
    FUN_00234210(this);
}
