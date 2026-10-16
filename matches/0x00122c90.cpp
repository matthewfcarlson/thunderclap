class Caster {
  public:
    virtual void Cast();
};
extern "C" void* Lookup(void*, Caster*);
class Target {
  public:
    void Set(void*);
};
void Run(Target* t, void* key) {
    Caster caster;
    t->Set(Lookup(key, &caster));
}