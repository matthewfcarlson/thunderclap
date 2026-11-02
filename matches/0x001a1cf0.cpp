class ConditionFactoryCasterTemplate_1a1cf0 {
  public:
    virtual void cast();
};
class Obj {
  public:
    void apply(void*);
};
extern "C" void* __cdecl lookup(const char*, ConditionFactoryCasterTemplate_1a1cf0*);
extern "C" void __cdecl FUN_001a1cf0(Obj* obj, const char* name) {
    ConditionFactoryCasterTemplate_1a1cf0 caster;
    obj->apply(lookup(name, &caster));
}