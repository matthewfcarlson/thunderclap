class Caster {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Apply(void*);
};
void* __cdecl Find(void*, Caster*);
void __cdecl FUN_001428b0(Obj* obj, void* source) {
    Caster c;
    obj->Apply(Find(source, &c));
}