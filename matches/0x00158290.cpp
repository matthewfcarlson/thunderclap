class Caster_158290 {
  public:
    virtual void f() {}
};
class Obj {
  public:
    void add(void*);
};
extern void* __cdecl find(void*, Caster_158290*);
void FUN_00158290(Obj* obj, void* name) {
    Caster_158290 caster;
    obj->add(find(name, &caster));
}