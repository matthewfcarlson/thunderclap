class Caster {
  public:
    virtual void Cast();
};
class Target {
  public:
    void* Do(void*);
};
extern "C" void* Find(void*, Caster*);
void* Func(Target* t, void* name) {
    Caster c;
    void* p = Find(name, &c);
    return t->Do(p);
}