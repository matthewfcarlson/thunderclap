class Caster {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Set(void*);
};
void* __cdecl Find(void*, Caster*);
void __cdecl FUN(Obj* obj, void* arg) {
    Caster caster;
    void* p = Find(arg, &caster);
    obj->Set(p);
}