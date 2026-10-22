class ConditionFactoryCasterTemplate_11a980 {
  public:
    virtual void Cast();
};
class SpecificCaster : public ConditionFactoryCasterTemplate_11a980 {
  public:
    virtual void Cast();
};
extern void* Find(int, ConditionFactoryCasterTemplate_11a980*);
class Owner {
  public:
    void Set(void*);
};
void Target(Owner* owner, int id) {
    SpecificCaster caster;
    void* result = Find(id, &caster);
    owner->Set(result);
}