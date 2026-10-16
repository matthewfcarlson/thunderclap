class Caster {
  public:
    virtual void cast();
};
class Owner {
  public:
    void Add(void*);
};
extern "C" void* __cdecl Find(void*, Caster*);
void __cdecl target(Owner* owner, void* key) {
    Caster caster;
    owner->Add(Find(key, &caster));
}