class TrackFactoryCasterTemplate_237ab0 {
  public:
    virtual void Cast();
};
class Target {
  public:
    void Method(void*);
};
extern "C" void* FUN_00236ac0(const char*, TrackFactoryCasterTemplate_237ab0*);
extern "C" void FUN_00237ab0(Target* target, const char* name) {
    TrackFactoryCasterTemplate_237ab0 caster;
    target->Method(FUN_00236ac0(name, &caster));
}
