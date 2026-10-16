class Caster {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Set(void*);
};
extern "C" void* __cdecl Find(void*, Caster*);
void __cdecl FUN_00158a10(Obj* obj, void* key) {
    Caster caster;
    void* p = Find(key, &caster);
    obj->Set(p);
}