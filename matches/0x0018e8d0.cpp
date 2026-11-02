class VarCaster {
  public:
    virtual void f();
};
class TrackFactoryCasterTemplate_18e8d0 {
  public:
    virtual void f();
};
extern "C" void* FUN_00236ac0(const char*, void*);
class Factory {
  public:
    void add(void*);
};
extern "C" void FUN_0018e8d0(Factory* p) {
    {
        VarCaster a;
        p->add(FUN_00236ac0("varAssign", &a));
    }
    {
        TrackFactoryCasterTemplate_18e8d0 b;
        p->add(FUN_00236ac0("timerSet", &b));
    }
}