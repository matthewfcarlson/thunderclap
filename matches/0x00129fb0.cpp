class TrackFactoryCasterTemplate_129fb0 {
  public:
    virtual void f();
};
class Target {
  public:
    void Run(void*);
};
extern "C" void* __cdecl FUN_00236ac0(void*, TrackFactoryCasterTemplate_129fb0*);
void Func(Target* target, void* name) {
    TrackFactoryCasterTemplate_129fb0 caster;
    void* p = FUN_00236ac0(name, &caster);
    target->Run(p);
}