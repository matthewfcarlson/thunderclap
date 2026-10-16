class Caster {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void Add(void*);
};
extern "C" void* __cdecl Find(void*, Caster*);
void Func(Owner* owner, void* name) {
    Caster caster;
    owner->Add(Find(name, &caster));
}