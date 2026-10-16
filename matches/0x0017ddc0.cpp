class Caster {
  public:
    virtual void cast();
};
extern "C" void* __cdecl lookup(void*, Caster*);
class Obj {
  public:
    void* use(void*);
};
void* fn(Obj* obj, void* key) {
    Caster caster;
    void* result = lookup(key, &caster);
    return obj->use(result);
}
