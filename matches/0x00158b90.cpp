class Caster {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void* Get(void*);
};
void* Find(void*, Caster*);
void* Target(Owner* owner, void* name) {
    Caster caster;
    return owner->Get(Find(name, &caster));
}