class Caster {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void Add(void*);
};
extern "C" void* Lookup(void*, Caster*);
void Func(Owner* owner, void* name) {
    Caster caster;
    void* result = Lookup(name, &caster);
    owner->Add(result);
}