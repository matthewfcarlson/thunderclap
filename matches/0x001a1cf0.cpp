class Caster {
  public:
    virtual void cast();
};
class Obj {
  public:
    void apply(void*);
};
extern "C" void* __cdecl lookup(const char*, Caster*);
void __cdecl target(Obj* obj, const char* name) {
    Caster caster;
    obj->apply(lookup(name, &caster));
}