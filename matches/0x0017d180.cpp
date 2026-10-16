class Caster {
  public:
    virtual void cast();
};
class Obj {
  public:
    void set(void*);
};
void* __cdecl find(const char*, Caster*);
void __cdecl FUN(Obj* obj, const char* name) {
    Caster caster;
    obj->set(find(name, &caster));
}