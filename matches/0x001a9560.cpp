class ConditionFactoryCasterTemplate_1a9560 {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void Apply(void*);
};
extern "C" void* __cdecl FUN_002343e0(void*, ConditionFactoryCasterTemplate_1a9560*);
void Fn(Owner* owner, void* value) {
    ConditionFactoryCasterTemplate_1a9560 caster;
    void* result = FUN_002343e0(value, &caster);
    owner->Apply(result);
}