class TrackFactoryCasterTemplate_132530 {
  public:
    virtual void Cast();
};
extern "C" void* __cdecl FUN_00236ac0(void*, TrackFactoryCasterTemplate_132530*);
class Owner {
  public:
    void Set(void*);
};
void __cdecl FUN_00132530(Owner* owner, void* name) {
    TrackFactoryCasterTemplate_132530 caster;
    void* p = FUN_00236ac0(name, &caster);
    owner->Set(p);
}