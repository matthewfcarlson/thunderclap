class ConditionFactoryCasterTemplate_23dd90 {
  public:
    virtual void cast();
};
class Obj {
  public:
    void use(void*);
};
extern "C" void* lookup(void*, ConditionFactoryCasterTemplate_23dd90*);
void target(Obj* a, void* b) {
    ConditionFactoryCasterTemplate_23dd90 caster;
    a->use(lookup(b, &caster));
}