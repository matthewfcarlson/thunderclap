class TrackFactoryCasterTemplate_158ad0 {
  public:
    virtual void cast();
};
class Track {};
class Owner {
  public:
    void bind(Track*);
};
Track* __cdecl lookup(void*, TrackFactoryCasterTemplate_158ad0*);
extern "C" void __cdecl FUN_00158ad0(Owner* owner, void* key) {
    TrackFactoryCasterTemplate_158ad0 caster;
    owner->bind(lookup(key, &caster));
}