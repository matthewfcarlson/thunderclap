class Caster {
  public:
    virtual void Cast();
};
extern void* Find(const char*, Caster*);
class Track {
  public:
    void Set(void*);
};
void fn(Track* track, const char* name) {
    Caster caster;
    void* found = Find(name, &caster);
    track->Set(found);
}