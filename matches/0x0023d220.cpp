class ConditionFactoryCasterTemplate_23d220 {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Apply(void*);
};
extern "C" void* Get(void*, ConditionFactoryCasterTemplate_23d220*);
extern "C" void FUN_0023d220(Obj* obj, void* x) {
    ConditionFactoryCasterTemplate_23d220 caster;
    void* p = Get(x, &caster);
    obj->Apply(p);
}