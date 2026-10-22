class TrackFactoryCasterTemplate_132530 {
  public:
    virtual void Cast();
};
extern "C" void* __cdecl Find(void*, TrackFactoryCasterTemplate_132530*);
class Owner {
  public:
    void Set(void*);
};
void __cdecl FUN_00132530(Owner* owner, void* name) {
    TrackFactoryCasterTemplate_132530 caster;
    void* p = Find(name, &caster);
    owner->Set(p);
}