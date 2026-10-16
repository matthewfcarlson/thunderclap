class Caster {
  public:
    virtual void Dummy();
};
class Obj {
  public:
    void Apply(void*);
};
void* __cdecl Find(const char*, Caster*);
void __cdecl FUN_0017cbd0(Obj* obj, const char* name) {
    Caster caster;
    obj->Apply(Find(name, &caster));
}