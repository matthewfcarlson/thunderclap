class Caster {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Set(void*);
};
void* __cdecl Find(const char*, Caster*);
extern "C" void FUN_0017dca0(Obj* obj, const char* name) {
    Caster caster;
    obj->Set(Find(name, &caster));
}
