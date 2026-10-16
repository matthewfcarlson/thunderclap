class Caster {
  public:
    virtual void Cast();
};
class Target {
  public:
    void Method(void*);
};
void* Lookup(const char*, Caster*);
void Func(Target* target, const char* name) {
    Caster caster;
    target->Method(Lookup(name, &caster));
}
