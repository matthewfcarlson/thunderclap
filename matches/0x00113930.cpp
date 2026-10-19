class Caster_113930 {
  public:
    virtual void Cast();
};
void* __cdecl Find(void*, Caster_113930*);
class Obj {
  public:
    void Apply(void*);
};
void __cdecl FUN_00113930(Obj* obj, void* item) {
    Caster_113930 caster;
    void* p = Find(item, &caster);
    obj->Apply(p);
}