class TrackFactoryCasterTemplate_18b0e0 {
  public:
    virtual void Cast();
    TrackFactoryCasterTemplate_18b0e0() {}
};
class Track {};
Track* __cdecl FUN_00236ac0(const char*, TrackFactoryCasterTemplate_18b0e0*);
class Owner {
  public:
    void Add(Track*);
};
void Register(Owner* owner, const char* name) {
    TrackFactoryCasterTemplate_18b0e0 caster;
    owner->Add(FUN_00236ac0(name, &caster));
}