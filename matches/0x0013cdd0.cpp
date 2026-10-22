class TrackFactoryCasterTemplate_13cdd0 {
  public:
    virtual void Cast();
};
class Track {};
Track* Find(const char*, TrackFactoryCasterTemplate_13cdd0*);
class Owner {
  public:
    Track* Add(Track*);
};
Track* Fun(Owner* owner, const char* name) {
    TrackFactoryCasterTemplate_13cdd0 caster;
    Track* p = Find(name, &caster);
    return owner->Add(p);
}