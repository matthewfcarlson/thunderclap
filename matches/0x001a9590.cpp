class ConditionFactoryCasterTemplate_1a9590 {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Apply(void*);
};
void* __cdecl Find(void*, ConditionFactoryCasterTemplate_1a9590*);
void __cdecl FUN(Obj* obj, void* value) {
    ConditionFactoryCasterTemplate_1a9590 caster;
    void* p = Find(value, &caster);
    obj->Apply(p);
}