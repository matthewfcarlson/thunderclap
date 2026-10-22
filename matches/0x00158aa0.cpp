class TrackFactoryCasterTemplate_158aa0 {
  public:
    virtual void Dummy();
};
class Track;
Track* Find(const char*, TrackFactoryCasterTemplate_158aa0*);
class Obj {
  public:
    void Set(Track*);
};
void Func(Obj* obj, const char* name) {
    TrackFactoryCasterTemplate_158aa0 caster;
    Track* track = Find(name, &caster);
    obj->Set(track);
}