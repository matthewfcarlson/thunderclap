class Caster {
  public:
    virtual void cast();
};
class Obj {
  public:
    void Set(void*);
};
void* __cdecl Find(const char*, Caster*);
void __cdecl Target(Obj* obj, const char* name) {
    Caster caster;
    obj->Set(Find(name, &caster));
}