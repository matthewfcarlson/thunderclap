class TrackFactoryCasterTemplate_18b0b0 {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void Add(void*);
};
extern "C" void* Lookup(void*, TrackFactoryCasterTemplate_18b0b0*);
void Func(Owner* owner, void* name) {
    TrackFactoryCasterTemplate_18b0b0 caster;
    void* result = Lookup(name, &caster);
    owner->Add(result);
}