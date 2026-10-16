class Caster {
  public:
    virtual void f();
};
class Obj {
  public:
    void use(void*);
};
void* __cdecl find(const char*, Caster*);
void __cdecl target(Obj* obj, const char* name) {
    Caster c;
    obj->use(find(name, &c));
}