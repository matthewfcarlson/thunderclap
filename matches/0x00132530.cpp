class Caster {
  public:
    virtual void Cast();
};
extern "C" void* __cdecl Find(void*, Caster*);
class Owner {
  public:
    void Set(void*);
};
void __cdecl FUN_00132530(Owner* owner, void* name) {
    Caster caster;
    void* p = Find(name, &caster);
    owner->Set(p);
}