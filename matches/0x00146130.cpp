class Caster_146130 {
  public:
    virtual void Cast();
};
extern void* __cdecl Find(const char*, Caster_146130*);
class Factory {
  public:
    void Add(void*);
};
void __cdecl Func(Factory* factory, const char* name) {
    Caster_146130 caster;
    factory->Add(Find(name, &caster));
}