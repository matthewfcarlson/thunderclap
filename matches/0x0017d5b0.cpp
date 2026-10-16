class Caster {
  public:
    virtual void cast();
};
extern void* __cdecl Find(const char*, Caster*);
class Obj {
  public:
    void Process(void*);
};
void Func(Obj* obj, const char* name) {
    Caster caster;
    void* p = Find(name, &caster);
    obj->Process(p);
}