class Caster_158bf0 {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Apply(void*);
};
extern "C" void* __cdecl Find(void*, Caster_158bf0*);
void Func(Obj* obj, void* name) {
    Caster_158bf0 caster;
    void* p = Find(name, &caster);
    obj->Apply(p);
}