class Caster {
  public:
    virtual void Cast();
};
extern void* __cdecl Find(const char*, Caster*);
class Factory {
  public:
    void Add(void*);
};
void __cdecl Func(Factory* factory, const char* name) {
    Caster caster;
    factory->Add(Find(name, &caster));
}