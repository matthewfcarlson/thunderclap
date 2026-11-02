class Caster_17cc00 {
  public:
    virtual void Cast();
};
extern void* Find(const char*, Caster_17cc00*);
class Track {
  public:
    void Set(void*);
};
extern "C" void FUN_0017cc00(Track* track, const char* name) {
    Caster_17cc00 caster;
    void* found = Find(name, &caster);
    track->Set(found);
}