class Caster_14b5a0 {
  public:
    virtual void Cast();
};
class Obj {
  public:
    int Get(void*);
};
extern "C" void* __cdecl Find(void*, Caster_14b5a0*);
int __cdecl F(Obj* obj, void* name) {
    Caster_14b5a0 caster;
    return obj->Get(Find(name, &caster));
}