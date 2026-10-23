class ConditionFactoryCaster_11a980 {
  public:
    virtual void Cast();
};
class ConditionFactoryCasterTemplate_11a980 : public ConditionFactoryCaster_11a980 {
  public:
    virtual void Cast();
};
extern void* Find(int, ConditionFactoryCaster_11a980*);
class Owner {
  public:
    void Set(void*);
};
void Target(Owner* owner, int id) {
    ConditionFactoryCasterTemplate_11a980 caster;
    void* result = Find(id, &caster);
    owner->Set(result);
}