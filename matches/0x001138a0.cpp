class Caster {
  public:
    virtual void Cast();
};
class Target {
  public:
    void Apply(void*);
};
void* __cdecl Find(void*, Caster*);
void FUN_001138a0(Target* target, void* value) {
    Caster caster;
    target->Apply(Find(value, &caster));
}