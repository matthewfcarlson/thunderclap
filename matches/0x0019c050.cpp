class TrackFactoryCasterTemplate_19c050 {
  public:
    virtual void Cast();
    TrackFactoryCasterTemplate_19c050() {}
};
class Owner {
  public:
    void Apply(void*);
};
extern "C" void* Lookup(void*, TrackFactoryCasterTemplate_19c050*);
extern "C" void FUN_0019c050(Owner* owner, void* value) {
    TrackFactoryCasterTemplate_19c050 caster;
    owner->Apply(Lookup(value, &caster));
}