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
class Track_236d60 : public Parent_236d60 {
  public:
    virtual ~Track_236d60();
    Ref_236d60* mRef;
};
Track_236d60::~Track_236d60() {
    if (mRef)
        mRef->Release(1);
    mRef = 0;
    FUN_00234210(this);
}
