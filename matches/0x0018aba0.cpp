class TrackFactoryCasterTemplate_18aba0 {
  public:
    virtual void cast();
};
class Owner {
  public:
    void Add(void*);
};
extern "C" void* __cdecl Find(void*, TrackFactoryCasterTemplate_18aba0*);
extern "C" void __cdecl FUN_0018aba0(Owner* owner, void* key) {
    TrackFactoryCasterTemplate_18aba0 caster;
    owner->Add(Find(key, &caster));
}