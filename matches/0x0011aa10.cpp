class ConditionFactoryCasterTemplate_11aa10 {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void Use(void*);
};
void* Find(void*, ConditionFactoryCasterTemplate_11aa10*);
void FUN_0011aa10(Owner* owner, void* name) {
    ConditionFactoryCasterTemplate_11aa10 c;
    owner->Use(Find(name, &c));
}