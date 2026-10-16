class Caster {
  public:
    virtual void cast();
};
void* __cdecl lookup(void*, Caster*);
class Obj {
  public:
    void* finish(void*);
};
void* __cdecl target(Obj* obj, void* name) {
    Caster caster;
    void* found = lookup(name, &caster);
    return obj->finish(found);
}