class Caster_17ca30 {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Set(void*);
};
extern "C" void* __cdecl Find(void*, Caster_17ca30*);
void __cdecl Func(Obj* obj, void* name) {
    Caster_17ca30 caster;
    obj->Set(Find(name, &caster));
}
