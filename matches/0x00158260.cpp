class Track;
class Caster_158260 {
  public:
    virtual Track* Cast(void*);
};
Track* FindTrack(const char*, Caster_158260*);
class Owner {
  public:
    void Apply(Track*);
};
void FUN_00158260(Owner* owner, const char* name) {
    Caster_158260 caster;
    Track* track = FindTrack(name, &caster);
    owner->Apply(track);
}