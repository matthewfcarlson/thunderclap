class ConditionFactoryCasterTemplate_23d420 {
  public:
    virtual void cast();
};
extern "C" void* Find(const char*, ConditionFactoryCasterTemplate_23d420*);
class Owner {
  public:
    void Apply(void*);
};
void Func(Owner* owner, const char* name) {
    ConditionFactoryCasterTemplate_23d420 caster;
    void* p = Find(name, &caster);
    owner->Apply(p);
}