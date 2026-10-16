class Caster {
  public:
    virtual void f();
};
class Obj {
  public:
    void apply(void*);
};
void* __cdecl find(const char*, Caster*);
void __cdecl target(Obj* obj, const char* name) {
    Caster caster;
    obj->apply(find(name, &caster));
}