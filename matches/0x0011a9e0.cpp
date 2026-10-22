class ConditionFactoryCasterTemplate_11a9e0 {
  public:
    virtual void cast();
};
class Obj {
  public:
    void use(void*);
};
extern "C" void* find(void*, ConditionFactoryCasterTemplate_11a9e0*);
void target(Obj* o, void* name) {
    ConditionFactoryCasterTemplate_11a9e0 caster;
    o->use(find(name, &caster));
}