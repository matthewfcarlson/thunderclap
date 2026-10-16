class Caster {
  public:
    virtual void Cast();
};
class Target {
  public:
    void Apply(void*);
};
void* Find(void*, Caster*);
void FUN_0014b3f0(Target* target, void* arg) {
    Caster caster;
    void* result = Find(arg, &caster);
    target->Apply(result);
}