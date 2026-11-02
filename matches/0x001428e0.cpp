class TrackFactoryCasterTemplate_1428e0 {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void Add(void*);
};
extern "C" void* __cdecl FUN_00236ac0(void*, TrackFactoryCasterTemplate_1428e0*);
extern "C" void FUN_001428e0(Owner* owner, void* name) {
    TrackFactoryCasterTemplate_1428e0 caster;
    owner->Add(FUN_00236ac0(name, &caster));
}