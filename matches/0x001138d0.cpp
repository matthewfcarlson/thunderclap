class Caster {
  public:
    virtual void Dummy();
};
extern "C" void* __cdecl Lookup(void*, Caster*);
class Object {
  public:
    void Set(void*);
};
void __cdecl Target(Object* obj, void* name) {
    Caster caster;
    void* p = Lookup(name, &caster);
    obj->Set(p);
}