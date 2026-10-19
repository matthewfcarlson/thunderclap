class Caster_1a9590 {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Apply(void*);
};
void* __cdecl Find(void*, Caster_1a9590*);
void __cdecl FUN(Obj* obj, void* value) {
    Caster_1a9590 caster;
    void* p = Find(value, &caster);
    obj->Apply(p);
}