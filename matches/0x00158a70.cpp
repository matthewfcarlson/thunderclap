class Caster {
  public:
    virtual void cast();
};
extern "C" void* __cdecl find(void*, Caster*);
class Object {
  public:
    void attach(void*);
};
void __cdecl target(Object* obj, void* name) {
    Caster caster;
    obj->attach(find(name, &caster));
}