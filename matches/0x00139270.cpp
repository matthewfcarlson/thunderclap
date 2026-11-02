class TrackFactoryCasterTemplate_139270 {
  public:
    virtual void f();
    TrackFactoryCasterTemplate_139270() {}
};
class Owner {
  public:
    void use(void*);
};
extern "C" void* __cdecl find(void*, TrackFactoryCasterTemplate_139270*);
extern "C" void FUN_00139270(Owner* owner, void* name) {
    TrackFactoryCasterTemplate_139270 caster;
    owner->use(find(name, &caster));
}