class Caster {
  public:
    virtual void cast();
};
extern "C" void* __cdecl Find(void*, Caster*);
class Obj {
  public:
    void Set(void*);
};
void Fn(Obj* obj, void* name) {
    Caster c;
    obj->Set(Find(name, &c));
}