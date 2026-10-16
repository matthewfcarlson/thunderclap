class Caster {
  public:
    virtual void Cast();
};
class Target {
  public:
    void Set(void*);
};
extern void* Find(void*, Caster*);
void Func(Target* target, void* name) {
    Caster caster;
    target->Set(Find(name, &caster));
}