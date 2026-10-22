class ConditionFactoryCasterTemplate_1ac340 {
  public:
    virtual void cast();
};
class Factory {
  public:
    void apply(void*);
};
void* __cdecl find(void*, ConditionFactoryCasterTemplate_1ac340*);
void __cdecl target(Factory* f, void* name) {
    ConditionFactoryCasterTemplate_1ac340 caster;
    f->apply(find(name, &caster));
}