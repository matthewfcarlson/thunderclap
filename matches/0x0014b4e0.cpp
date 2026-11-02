class TrackFactoryCasterTemplate_14b4e0 {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void Add(void*);
};
void* FUN_00236ac0(const char*, TrackFactoryCasterTemplate_14b4e0*);
extern "C" void FUN_0014b4e0(Owner* owner, const char* name) {
    TrackFactoryCasterTemplate_14b4e0 caster;
    void* p = FUN_00236ac0(name, &caster);
    owner->Add(p);
}