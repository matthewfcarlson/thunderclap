class Caster {
  public:
    virtual void Cast();
};
class Track {
  public:
    void Add(void*);
};
extern "C" void* Find(const char*, Caster*);
void Do(Track* track, const char* name) {
    Caster caster;
    track->Add(Find(name, &caster));
}