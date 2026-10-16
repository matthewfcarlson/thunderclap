class Caster {
  public:
    virtual void Cast();
};
class Track {
  public:
    void* Make(void*);
};
extern "C" void* GetTrack(void*, Caster*);
void* Wrap(Track* t, void* p) {
    Caster c;
    void* r = GetTrack(p, &c);
    return t->Make(r);
}