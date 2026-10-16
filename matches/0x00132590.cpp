class Caster {
  public:
    virtual void f();
};
extern "C" void* __cdecl Find(char*, Caster*);
class Owner {
  public:
    void Add(void*);
};
void __cdecl target(Owner* owner, char* name) {
    Caster caster;
    owner->Add(Find(name, &caster));
}