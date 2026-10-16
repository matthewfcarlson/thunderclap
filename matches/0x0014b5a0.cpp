class Caster {
  public:
    virtual void Cast();
};
class Obj {
  public:
    int Get(void*);
};
extern "C" void* __cdecl Find(void*, Caster*);
int __cdecl F(Obj* obj, void* name) {
    Caster caster;
    return obj->Get(Find(name, &caster));
}