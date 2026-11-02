class TrackFactoryCasterTemplate_1a9a90 {
  public:
    virtual void dummy();
};
extern "C" void* __cdecl FUN_00236ac0(const char*, TrackFactoryCasterTemplate_1a9a90*);
class Owner {
  public:
    void accept(void*);
};
extern "C" void __cdecl FUN_001a9a90(Owner* owner, const char* name) {
    TrackFactoryCasterTemplate_1a9a90 caster;
    owner->accept(FUN_00236ac0(name, &caster));
}
