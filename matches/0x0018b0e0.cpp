class Caster {
  public:
    virtual void Cast();
    Caster() {}
};
class Track {};
Track* __cdecl Find(const char*, Caster*);
class Owner {
  public:
    void Add(Track*);
};
void Register(Owner* owner, const char* name) {
    Caster caster;
    owner->Add(Find(name, &caster));
}