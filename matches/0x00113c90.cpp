class Caster {
  public:
    virtual void Cast();
};
void* __cdecl Find(void*, Caster*);
class Owner {
  public:
    void* Get(void*);
};
extern "C" void* __cdecl FUN_00113c90(Owner* owner, void* p) {
    Caster caster;
    void* x = Find(p, &caster);
    return owner->Get(x);
}