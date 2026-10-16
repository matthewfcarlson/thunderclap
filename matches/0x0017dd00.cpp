class Caster {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Act(void*);
};
void* __cdecl Find(void*, Caster*);
void __cdecl Target(Obj* obj, void* p) {
    Caster caster;
    obj->Act(Find(p, &caster));
}