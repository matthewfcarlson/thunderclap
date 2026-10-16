class Caster {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void Apply(void*);
};
extern "C" void* __cdecl Find(void*, Caster*);
void Fn(Owner* owner, void* value) {
    Caster caster;
    void* result = Find(value, &caster);
    owner->Apply(result);
}