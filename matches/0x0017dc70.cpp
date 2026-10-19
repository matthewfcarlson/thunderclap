class Caster_17dc70 {
  public:
    virtual void foo();
};
class Track {
  public:
    void apply(void*);
};
extern "C" void* __cdecl find(void*, Caster_17dc70*);
void __cdecl target(Track* track, void* name) {
    Caster_17dc70 caster;
    track->apply(find(name, &caster));
}