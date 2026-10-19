class Caster_18a840 {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Set(void*);
};
extern "C" void* __cdecl Find(const char*, Caster_18a840*);
void __cdecl Target(Obj* obj, const char* name) {
    Caster_18a840 caster;
    void* p = Find(name, &caster);
    obj->Set(p);
}