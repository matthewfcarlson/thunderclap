class Caster {
  public:
    virtual void Cast();
};
extern "C" void* __cdecl Find(void*, Caster*);
class Obj {
  public:
    void Take(void*);
};
void __cdecl target(Obj* obj, void* value) {
    Caster caster;
    obj->Take(Find(value, &caster));
}