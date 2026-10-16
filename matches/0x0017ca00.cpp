class Caster {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Apply(void*);
};
extern "C" void* __cdecl Find(void*, Caster*);
void __cdecl FUN_0017ca00(Obj* obj, void* value) {
    Caster caster;
    void* p = Find(value, &caster);
    obj->Apply(p);
}