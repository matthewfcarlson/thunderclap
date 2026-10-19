class Caster_18b0b0 {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void Add(void*);
};
extern "C" void* Lookup(void*, Caster_18b0b0*);
void Func(Owner* owner, void* name) {
    Caster_18b0b0 caster;
    void* result = Lookup(name, &caster);
    owner->Add(result);
}