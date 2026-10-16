class Caster {
  public:
    virtual void cast();
};
class Track {
  public:
    void Set(void*);
};
extern "C" void* __cdecl Find(const char*, Caster*);
void __cdecl Target(Track* t, const char* name) {
    Caster caster;
    t->Set(Find(name, &caster));
}