class Track;
class TrackFactoryCasterTemplate_158260 {
  public:
    virtual Track* Cast(void*);
};
Track* FindTrack(const char*, TrackFactoryCasterTemplate_158260*);
class Owner {
  public:
    void Apply(Track*);
};
void FUN_00158260(Owner* owner, const char* name) {
    TrackFactoryCasterTemplate_158260 caster;
    Track* track = FindTrack(name, &caster);
    owner->Apply(track);
}