class Caster {
  public:
    virtual void Cast();
};
void* __cdecl Find(void*, Caster*);
class Owner {
  public:
    void* Get(void*);
};
void* __cdecl Target(Owner* owner, void* p) {
    Caster caster;
    void* x = Find(p, &caster);
    return owner->Get(x);
}