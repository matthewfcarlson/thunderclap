class ConditionFactoryCasterTemplate_2391d0 {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Set(void*);
};
extern "C" void* Find(const char*, ConditionFactoryCasterTemplate_2391d0*);
extern "C" void FUN_002391d0(Obj* obj, const char* name) {
    ConditionFactoryCasterTemplate_2391d0 caster;
    obj->Set(Find(name, &caster));
}