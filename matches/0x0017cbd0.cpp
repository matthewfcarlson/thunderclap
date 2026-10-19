class Caster_17cbd0 {
  public:
    virtual void Dummy();
};
class Obj {
  public:
    void Apply(void*);
};
void* __cdecl Find(const char*, Caster_17cbd0*);
void __cdecl FUN_0017cbd0(Obj* obj, const char* name) {
    Caster_17cbd0 caster;
    obj->Apply(Find(name, &caster));
}