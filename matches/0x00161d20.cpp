class Caster_161d20 {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void Apply(void*);
};
void* __cdecl Find(void*, Caster_161d20*);
void __cdecl FUN_00161d20(Owner* owner, void* source) {
    Caster_161d20 caster;
    owner->Apply(Find(source, &caster));
}