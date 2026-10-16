class Caster {
  public:
    virtual void f();
    Caster() {}
};
class Owner {
  public:
    void use(void*);
};
extern "C" void* __cdecl find(void*, Caster*);
void func(Owner* owner, void* name) {
    Caster caster;
    owner->use(find(name, &caster));
}