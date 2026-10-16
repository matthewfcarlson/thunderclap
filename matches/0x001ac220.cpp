class Caster {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void Apply(void*);
};
void* __cdecl Find(const char*, Caster*);
void FUN_001ac220(Owner* owner, const char* name) {
    Caster c;
    owner->Apply(Find(name, &c));
}