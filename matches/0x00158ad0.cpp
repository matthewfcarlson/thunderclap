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
void __cdecl target(Owner* owner, void* key) {
    TrackFactoryCasterTemplate_158ad0 caster;
    owner->bind(lookup(key, &caster));
}