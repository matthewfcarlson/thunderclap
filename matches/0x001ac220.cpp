class ConditionFactoryCasterTemplate_1ac220 {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void Apply(void*);
};
void* __cdecl Find(const char*, ConditionFactoryCasterTemplate_1ac220*);
void FUN_001ac220(Owner* owner, const char* name) {
    ConditionFactoryCasterTemplate_1ac220 c;
    owner->Apply(Find(name, &c));
}