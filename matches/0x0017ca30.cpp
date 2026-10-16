class Caster {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Set(void*);
};
extern "C" void* __cdecl Find(void*, Caster*);
void __cdecl Func(Obj* obj, void* name) {
    Caster caster;
    obj->Set(Find(name, &caster));
}
