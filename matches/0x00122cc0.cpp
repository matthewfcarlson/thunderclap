class TrackFactoryCasterTemplate_122cc0 {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void Apply(void*);
};
extern void* Find(const char*, TrackFactoryCasterTemplate_122cc0*);
extern "C" void FUN_00122cc0(Owner* owner, const char* name) {
    TrackFactoryCasterTemplate_122cc0 caster;
    owner->Apply(Find(name, &caster));
}