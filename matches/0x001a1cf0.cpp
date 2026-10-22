class ConditionFactoryCasterTemplate_1a1cf0 {
  public:
    virtual void cast();
};
class Obj {
  public:
    void apply(void*);
};
extern "C" void* __cdecl lookup(const char*, ConditionFactoryCasterTemplate_1a1cf0*);
void __cdecl target(Obj* obj, const char* name) {
    ConditionFactoryCasterTemplate_1a1cf0 caster;
    obj->apply(lookup(name, &caster));
}