class Caster {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Apply(void*);
};
extern "C" void* __cdecl Find(void*, Caster*);
void Func(Obj* obj, void* name) {
    Caster caster;
    void* p = Find(name, &caster);
    obj->Apply(p);
}