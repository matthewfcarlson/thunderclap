class Caster {
  public:
    virtual void f();
};
class Obj {
  public:
    void Set(void*);
};
extern "C" void* __cdecl Find(void*, Caster*);
extern "C" void FUN_0017dd90(Obj* obj, void* name) {
    Caster caster;
    void* p = Find(name, &caster);
    obj->Set(p);
}