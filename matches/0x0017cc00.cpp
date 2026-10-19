class Caster_17cc00 {
  public:
    virtual void Cast();
};
extern void* Find(const char*, Caster_17cc00*);
class Track {
  public:
    void Set(void*);
};
void fn(Track* track, const char* name) {
    Caster_17cc00 caster;
    void* found = Find(name, &caster);
    track->Set(found);
}