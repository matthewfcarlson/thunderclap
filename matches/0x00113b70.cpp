class Caster_113b70 {
  public:
    virtual void Cast();
};
class SpecificCaster : public Caster_113b70 {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void Set(void*);
};
void* __cdecl Find(void*, Caster_113b70*);
void __cdecl FUN_00113b70(Owner* owner, void* key) {
    SpecificCaster caster;
    owner->Set(Find(key, &caster));
}