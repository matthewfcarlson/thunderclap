class Caster_122cc0 {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void Apply(void*);
};
extern void* Find(const char*, Caster_122cc0*);
void Func(Owner* owner, const char* name) {
    Caster_122cc0 caster;
    owner->Apply(Find(name, &caster));
}