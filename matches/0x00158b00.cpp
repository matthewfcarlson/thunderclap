class Caster {
  public:
    virtual void Cast();
};
struct Obj {
    void Fn(void*);
};
void* __cdecl Find(void*, Caster*);
void __cdecl Target(Obj* obj, void* name) {
    Caster caster;
    void* result = Find(name, &caster);
    obj->Fn(result);
}