class Caster {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Apply(void*);
};
extern void* __cdecl Find(void*, Caster*);
void Func(Obj* obj, void* arg) {
    Caster caster;
    obj->Apply(Find(arg, &caster));
}