class TrackFactoryCasterTemplate_1325c0 {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void Set(void*);
};
extern "C" void* FUN_00236ac0(const char*, TrackFactoryCasterTemplate_1325c0*);
void Func(Owner* owner, const char* name) {
    TrackFactoryCasterTemplate_1325c0 caster;
    void* p = FUN_00236ac0(name, &caster);
    owner->Set(p);
}