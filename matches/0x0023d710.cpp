class ConditionFactoryCasterTemplate_23d710 {
  public:
    virtual void Dummy();
};
class Owner {
  public:
    void Set(void*);
};
extern "C" void* FUN_002343e0(void*, ConditionFactoryCasterTemplate_23d710*);
extern "C" void FUN_0023d710(Owner* owner, void* ptr) {
    ConditionFactoryCasterTemplate_23d710 caster;
    owner->Set(FUN_002343e0(ptr, &caster));
}