class Caster_158a40 {
  public:
    virtual void f();
};
class Obj {
  public:
    void use(void*);
};
void* __cdecl find(const char*, Caster_158a40*);
void __cdecl target(Obj* obj, const char* name) {
    Caster_158a40 c;
    obj->use(find(name, &c));
}