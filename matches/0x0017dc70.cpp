class Caster {
  public:
    virtual void foo();
};
class Track {
  public:
    void apply(void*);
};
extern "C" void* __cdecl find(void*, Caster*);
void __cdecl target(Track* track, void* name) {
    Caster caster;
    track->apply(find(name, &caster));
}