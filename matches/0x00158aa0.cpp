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
extern "C" void FUN_00158aa0(Obj* obj, const char* name) {
    TrackFactoryCasterTemplate_158aa0 caster;
    Track* track = Find(name, &caster);
    obj->Set(track);
}