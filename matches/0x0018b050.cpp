class TrackFactoryCasterTemplate_18b050 {
  public:
    virtual void Cast();
};
void* __cdecl FUN_00236ac0(void*, TrackFactoryCasterTemplate_18b050*);
class Owner {
  public:
    void Set(void*);
};
void __cdecl FUN_0018b050(Owner* owner, void* item) {
    TrackFactoryCasterTemplate_18b050 caster;
    void* p = FUN_00236ac0(item, &caster);
    owner->Set(p);
}