class Caster_17d870 {
  public:
    virtual void f();
};
class Track {
  public:
    void get(void*);
};
extern "C" void* __cdecl find(void*, Caster_17d870*);
void func(Track* t, void* name) {
    Caster_17d870 c;
    t->get(find(name, &c));
}