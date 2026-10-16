class Caster {
  public:
    virtual void Cast();
};
class Track;
Track* Find(void*, Caster*);
class Factory {
  public:
    void Add(Track*);
};
void Target(Factory* factory, void* name) {
    Caster caster;
    Track* track = Find(name, &caster);
    factory->Add(track);
}