class ConditionFactoryCasterTemplate_23dd90 {
  public:
    virtual void cast();
};
class Obj {
  public:
    void use(void*);
};
extern "C" void* lookup(void*, ConditionFactoryCasterTemplate_23dd90*);
extern "C" void FUN_0023dd90(Obj* a, void* b) {
    ConditionFactoryCasterTemplate_23dd90 caster;
    a->use(lookup(b, &caster));
}