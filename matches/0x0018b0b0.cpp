class TrackFactoryCasterTemplate_18b0b0 {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void Add(void*);
};
extern "C" void* Lookup(void*, TrackFactoryCasterTemplate_18b0b0*);
extern "C" void FUN_0018b0b0(Owner* owner, void* name) {
    TrackFactoryCasterTemplate_18b0b0 caster;
    void* result = Lookup(name, &caster);
    owner->Add(result);
}