class Caster_1138a0 {
  public:
    virtual void Cast();
};
class Target {
  public:
    void Apply(void*);
};
void* __cdecl Find(void*, Caster_1138a0*);
void FUN_001138a0(Target* target, void* value) {
    Caster_1138a0 caster;
    target->Apply(Find(value, &caster));
}