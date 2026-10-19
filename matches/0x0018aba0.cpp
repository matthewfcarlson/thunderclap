class Caster_18aba0 {
  public:
    virtual void cast();
};
class Owner {
  public:
    void Add(void*);
};
extern "C" void* __cdecl Find(void*, Caster_18aba0*);
void __cdecl target(Owner* owner, void* key) {
    Caster_18aba0 caster;
    owner->Add(Find(key, &caster));
}