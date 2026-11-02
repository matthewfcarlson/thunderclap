class TrackFactoryCasterTemplate_158b90 {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void* Get(void*);
};
void* Find(void*, TrackFactoryCasterTemplate_158b90*);
extern "C" void* FUN_00158b90(Owner* owner, void* name) {
    TrackFactoryCasterTemplate_158b90 caster;
    return owner->Get(Find(name, &caster));
}