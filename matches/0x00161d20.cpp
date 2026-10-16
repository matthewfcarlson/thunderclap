class Caster {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void Apply(void*);
};
void* __cdecl Find(void*, Caster*);
void __cdecl FUN_00161d20(Owner* owner, void* source) {
    Caster caster;
    owner->Apply(Find(source, &caster));
}