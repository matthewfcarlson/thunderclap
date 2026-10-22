class ConditionFactoryCasterTemplate_23d710 {
  public:
    virtual void Dummy();
};
class Owner {
  public:
    void Set(void*);
};
extern void* Cast(void*, ConditionFactoryCasterTemplate_23d710*);
void Func(Owner* owner, void* ptr) {
    ConditionFactoryCasterTemplate_23d710 caster;
    owner->Set(Cast(ptr, &caster));
}