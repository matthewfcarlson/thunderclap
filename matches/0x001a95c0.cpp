class Caster {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Do(void*);
};
void* __cdecl Find(void*, Caster*);
void __cdecl Target(Obj* obj, void* p) {
    Caster caster;
    obj->Do(Find(p, &caster));
}