class Caster {
  public:
    virtual void Cast();
    Caster() {}
};
class Owner {
  public:
    void Apply(void*);
};
extern "C" void* Lookup(void*, Caster*);
void Target(Owner* owner, void* value) {
    Caster caster;
    owner->Apply(Lookup(value, &caster));
}