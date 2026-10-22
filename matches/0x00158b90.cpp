class TrackFactoryCasterTemplate_158b90 {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void* Get(void*);
};
void* Find(void*, TrackFactoryCasterTemplate_158b90*);
void* Target(Owner* owner, void* name) {
    TrackFactoryCasterTemplate_158b90 caster;
    return owner->Get(Find(name, &caster));
}