class Caster {
  public:
    virtual void cast();
};
class Track {
  public:
    void apply(void*);
};
extern "C" void* find(void*, Caster*);
void target(Track* track, void* name) {
    Caster caster;
    track->apply(find(name, &caster));
}