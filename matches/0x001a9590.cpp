class Caster {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Apply(void*);
};
void* __cdecl Find(void*, Caster*);
void __cdecl FUN(Obj* obj, void* value) {
    Caster caster;
    void* p = Find(value, &caster);
    obj->Apply(p);
}