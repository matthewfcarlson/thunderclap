class Caster_132560 {
  public:
    virtual void f();
};
class Obj {
  public:
    void apply(void*);
};
void* __cdecl find(const char*, Caster_132560*);
void __cdecl target(Obj* obj, const char* name) {
    Caster_132560 caster;
    obj->apply(find(name, &caster));
}