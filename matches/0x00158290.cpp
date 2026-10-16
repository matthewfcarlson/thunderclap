class Caster {
  public:
    virtual void f() {}
};
class Obj {
  public:
    void add(void*);
};
extern void* __cdecl find(void*, Caster*);
void FUN_00158290(Obj* obj, void* name) {
    Caster caster;
    obj->add(find(name, &caster));
}