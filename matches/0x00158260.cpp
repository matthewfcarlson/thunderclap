class Track;
class Caster {
  public:
    virtual Track* Cast(void*);
};
Track* FindTrack(const char*, Caster*);
class Owner {
  public:
    void Apply(Track*);
};
void FUN_00158260(Owner* owner, const char* name) {
    Caster caster;
    Track* track = FindTrack(name, &caster);
    owner->Apply(track);
}