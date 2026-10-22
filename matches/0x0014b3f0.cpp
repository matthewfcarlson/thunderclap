class ConditionFactoryCasterTemplate_14b3f0 {
  public:
    virtual void Cast();
};
class Target {
  public:
    void Apply(void*);
};
void* Find(void*, ConditionFactoryCasterTemplate_14b3f0*);
void FUN_0014b3f0(Target* target, void* arg) {
    ConditionFactoryCasterTemplate_14b3f0 caster;
    void* result = Find(arg, &caster);
    target->Apply(result);
}