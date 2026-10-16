class Caster {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void Apply(void*);
};
extern void* Find(const char*, Caster*);
void Func(Owner* owner, const char* name) {
    Caster caster;
    owner->Apply(Find(name, &caster));
}