class ConditionFactoryCasterTemplate_1ac340 {
  public:
    virtual void cast();
};
class Factory {
  public:
    void apply(void*);
};
void* __cdecl find(void*, ConditionFactoryCasterTemplate_1ac340*);
extern "C" void __cdecl FUN_001ac340(Factory* f, void* name) {
    ConditionFactoryCasterTemplate_1ac340 caster;
    f->apply(find(name, &caster));
}