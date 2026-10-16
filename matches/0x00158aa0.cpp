class Caster {
  public:
    virtual void Dummy();
};
class Track;
Track* Find(const char*, Caster*);
class Obj {
  public:
    void Set(Track*);
};
void Func(Obj* obj, const char* name) {
    Caster caster;
    Track* track = Find(name, &caster);
    obj->Set(track);
}