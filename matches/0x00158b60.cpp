class Caster {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Set(void*);
};
extern "C" void* __cdecl Find(const char*, Caster*);
void Func(Obj* obj, const char* name) {
    Caster caster;
    void* p = Find(name, &caster);
    obj->Set(p);
}