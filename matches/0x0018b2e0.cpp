class TrackFactoryCasterTemplate_18b2e0 {
  public:
    virtual void Cast();
};
extern "C" void* __cdecl FUN_00236ac0(void*, TrackFactoryCasterTemplate_18b2e0*);
class Target {
  public:
    void* Set(void*);
};
void* __cdecl FUN_0018b2e0(Target* target, void* arg) {
    TrackFactoryCasterTemplate_18b2e0 caster;
    void* p = FUN_00236ac0(arg, &caster);
    return target->Set(p);
}