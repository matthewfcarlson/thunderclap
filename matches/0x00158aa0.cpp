class Caster_158aa0 {
  public:
    virtual void Dummy();
};
class Track;
Track* Find(const char*, Caster_158aa0*);
class Obj {
  public:
    void Set(Track*);
};
void Func(Obj* obj, const char* name) {
    Caster_158aa0 caster;
    Track* track = Find(name, &caster);
    obj->Set(track);
}