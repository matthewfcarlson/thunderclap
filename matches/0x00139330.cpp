class Caster_139330 {
  public:
    virtual void Cast();
};
class Track {
  public:
    void* Make(void*);
};
extern "C" void* GetTrack(void*, Caster_139330*);
void* Wrap(Track* t, void* p) {
    Caster_139330 c;
    void* r = GetTrack(p, &c);
    return t->Make(r);
}