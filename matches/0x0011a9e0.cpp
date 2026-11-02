class ConditionFactoryCasterTemplate_11a9e0 {
  public:
    virtual void cast();
};
class Obj {
  public:
    void use(void*);
};
extern "C" void* FUN_002343e0(void*, ConditionFactoryCasterTemplate_11a9e0*);
extern "C" void FUN_0011a9e0(Obj* o, void* name) {
    ConditionFactoryCasterTemplate_11a9e0 caster;
    o->use(FUN_002343e0(name, &caster));
}