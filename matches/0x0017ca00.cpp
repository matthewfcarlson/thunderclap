class Caster_17ca00 {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Apply(void*);
};
extern "C" void* __cdecl Find(void*, Caster_17ca00*);
void __cdecl FUN_0017ca00(Obj* obj, void* value) {
    Caster_17ca00 caster;
    void* p = Find(value, &caster);
    obj->Apply(p);
}