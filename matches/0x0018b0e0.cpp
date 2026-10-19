class Caster_18b0e0 {
  public:
    virtual void Cast();
    Caster_18b0e0() {}
};
class Track {};
Track* __cdecl Find(const char*, Caster_18b0e0*);
class Owner {
  public:
    void Add(Track*);
};
void Register(Owner* owner, const char* name) {
    Caster_18b0e0 caster;
    owner->Add(Find(name, &caster));
}