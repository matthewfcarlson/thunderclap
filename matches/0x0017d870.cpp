class Caster {
  public:
    virtual void f();
};
class Track {
  public:
    void get(void*);
};
extern "C" void* __cdecl find(void*, Caster*);
void func(Track* t, void* name) {
    Caster c;
    t->get(find(name, &c));
}