class Caster_1a94d0 {
  public:
    virtual void Cast();
};
extern "C" void* __cdecl Find(void*, Caster_1a94d0*);
class Factory {
  public:
    void Use(void*);
};
void __cdecl Target(Factory* factory, void* item) {
    Caster_1a94d0 caster;
    factory->Use(Find(item, &caster));
}
