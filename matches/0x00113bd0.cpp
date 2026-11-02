class Caster_113bd0 {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Apply(void*);
};
extern void* __cdecl Find(void*, Caster_113bd0*);
extern "C" void FUN_00113bd0(Obj* obj, void* arg) {
    Caster_113bd0 caster;
    obj->Apply(Find(arg, &caster));
}