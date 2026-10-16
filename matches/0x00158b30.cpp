class Caster {
  public:
    virtual void cast();
};
class Obj {
  public:
    void set(void*);
};
extern "C" void* __cdecl find(const char*, Caster*);
void f(Obj* obj, const char* name) {
    Caster c;
    obj->set(find(name, &c));
}