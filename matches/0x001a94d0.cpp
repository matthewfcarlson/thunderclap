class Caster {
  public:
    virtual void Cast();
};
extern "C" void* __cdecl Find(void*, Caster*);
class Factory {
  public:
    void Use(void*);
};
void __cdecl Target(Factory* factory, void* item) {
    Caster caster;
    factory->Use(Find(item, &caster));
}
