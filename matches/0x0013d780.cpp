class Caster {
  public:
    virtual void Cast();
};
class Target {
  public:
    void Set(void*);
};
extern "C" void* __cdecl Find(const char*, Caster*);
void __cdecl f(Target* t, const char* name) {
    Caster caster;
    void* p = Find(name, &caster);
    t->Set(p);
}