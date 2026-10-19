class Caster_191910 {
  public:
    virtual void cast();
};
class Obj {
  public:
    void Set(void*);
};
void* __cdecl Find(const char*, Caster_191910*);
void __cdecl Target(Obj* obj, const char* name) {
    Caster_191910 caster;
    obj->Set(Find(name, &caster));
}