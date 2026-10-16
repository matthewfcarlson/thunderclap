class Caster {
  public:
    virtual void f();
};
void* __cdecl resolve(void*, Caster*);
class Obj {
  public:
    void use(void*);
};
void work(Obj* obj, void* id) {
    Caster caster;
    void* p = resolve(id, &caster);
    obj->use(p);
}