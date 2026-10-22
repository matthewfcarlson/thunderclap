void* __cdecl operator new(unsigned int) throw();
class Condition_12acf0 {
  public:
    Condition_12acf0(int) throw();
    virtual void v0();
    virtual void v1();
    virtual void v2();
    char pad[8];
};
class TargetFirstShotCondition : public Condition_12acf0 {
  public:
    TargetFirstShotCondition() throw() : Condition_12acf0(0) { flag = 1; }
    virtual void v0();
    char flag;
};
class ConditionFactory {
  public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual Condition_12acf0* vfunc_5();
};
Condition_12acf0* ConditionFactory::vfunc_5() {
    return new TargetFirstShotCondition;
}