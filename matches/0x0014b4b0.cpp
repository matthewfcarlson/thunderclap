class TrackFactoryCasterTemplate_14b4b0 {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void Set(void*);
};
extern "C" void* __cdecl FUN_00236ac0(const char*, TrackFactoryCasterTemplate_14b4b0*);
void Func(Owner* owner, const char* name) {
    TrackFactoryCasterTemplate_14b4b0 caster;
    void* p = FUN_00236ac0(name, &caster);
    owner->Set(p);
}