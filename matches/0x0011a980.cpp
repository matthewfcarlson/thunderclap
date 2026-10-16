class Caster {
  public:
    virtual void Cast();
};
class SpecificCaster : public Caster {
  public:
    virtual void Cast();
};
extern void* Find(int, Caster*);
class Owner {
  public:
    void Set(void*);
};
void Target(Owner* owner, int id) {
    SpecificCaster caster;
    void* result = Find(id, &caster);
    owner->Set(result);
}