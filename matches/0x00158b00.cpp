class Caster_158b00 {
  public:
    virtual void Cast();
};
struct Obj {
    void Fn(void*);
};
void* __cdecl Find(void*, Caster_158b00*);
void __cdecl Target(Obj* obj, void* name) {
    Caster_158b00 caster;
    void* result = Find(name, &caster);
    obj->Fn(result);
}