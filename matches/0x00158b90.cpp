class Caster_158b90 {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void* Get(void*);
};
void* Find(void*, Caster_158b90*);
void* Target(Owner* owner, void* name) {
    Caster_158b90 caster;
    return owner->Get(Find(name, &caster));
}