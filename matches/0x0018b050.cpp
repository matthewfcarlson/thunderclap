class Caster_18b050 {
  public:
    virtual void Cast();
};
void* __cdecl Lookup(void*, Caster_18b050*);
class Owner {
  public:
    void Set(void*);
};
void __cdecl FUN_0018b050(Owner* owner, void* item) {
    Caster_18b050 caster;
    void* p = Lookup(item, &caster);
    owner->Set(p);
}