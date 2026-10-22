class ConditionFactoryCasterTemplate_1a9560 {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void Apply(void*);
};
extern "C" void* __cdecl Find(void*, ConditionFactoryCasterTemplate_1a9560*);
void Fn(Owner* owner, void* value) {
    ConditionFactoryCasterTemplate_1a9560 caster;
    void* result = Find(value, &caster);
    owner->Apply(result);
}