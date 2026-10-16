class Caster {
  public:
    virtual void Cast();
};
void* __cdecl Lookup(void*, Caster*);
class Owner {
  public:
    void Set(void*);
};
void __cdecl FUN_0018b050(Owner* owner, void* item) {
    Caster caster;
    void* p = Lookup(item, &caster);
    owner->Set(p);
}