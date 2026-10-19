class Caster_1428b0 {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Apply(void*);
};
void* __cdecl Find(void*, Caster_1428b0*);
void __cdecl FUN_001428b0(Obj* obj, void* source) {
    Caster_1428b0 c;
    obj->Apply(Find(source, &c));
}