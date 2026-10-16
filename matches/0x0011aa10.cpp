class Caster {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void Use(void*);
};
void* Find(void*, Caster*);
void FUN_0011aa10(Owner* owner, void* name) {
    Caster c;
    owner->Use(Find(name, &c));
}