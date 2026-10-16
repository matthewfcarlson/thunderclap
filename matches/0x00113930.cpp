class Caster {
  public:
    virtual void Cast();
};
void* __cdecl Find(void*, Caster*);
class Obj {
  public:
    void Apply(void*);
};
void __cdecl FUN_00113930(Obj* obj, void* item) {
    Caster caster;
    void* p = Find(item, &caster);
    obj->Apply(p);
}