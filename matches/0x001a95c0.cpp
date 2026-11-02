class ConditionFactoryCasterTemplate_1a95c0 {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Do(void*);
};
void* __cdecl Find(void*, ConditionFactoryCasterTemplate_1a95c0*);
extern "C" void __cdecl FUN_001a95c0(Obj* obj, void* p) {
    ConditionFactoryCasterTemplate_1a95c0 caster;
    obj->Do(Find(p, &caster));
}