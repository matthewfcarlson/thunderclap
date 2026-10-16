class Caster {
  public:
    virtual void Cast();
};
extern "C" void* __cdecl Find(void*, Caster*);
class Obj {
  public:
    void Set(void*);
};
void func(Obj* obj, void* name) {
    Caster caster;
    obj->Set(Find(name, &caster));
}