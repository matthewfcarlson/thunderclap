typedef unsigned int size_t;
void* operator new(size_t) throw();
namespace fight {
class Arg;
class Part {
  public:
    Part(Arg*) throw();
    char data[8];
};
class BaseCond {
  public:
    BaseCond() throw();
    virtual void f();
    char pad[4];
};
class CIsInvincibleCondition : public BaseCond {
  public:
    CIsInvincibleCondition(Arg* a) throw() : BaseCond(), part(a) {}
    virtual void f();
    Part part;
};
class ConditionFactoryCaster {
  public:
    virtual void vfunc_0();
    virtual CIsInvincibleCondition* vfunc_1(Arg*);
};
class ConditionFactoryCasterTemplate : public ConditionFactoryCaster {
  public:
    virtual void vfunc_0();
    virtual CIsInvincibleCondition* vfunc_1(Arg*);
};
CIsInvincibleCondition* ConditionFactoryCasterTemplate::vfunc_1(Arg* a) {
    return new CIsInvincibleCondition(a);
}
} // namespace fight
