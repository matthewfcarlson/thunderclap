class Caster_19c720 {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Set(void*);
};
void* __cdecl Find(void*, Caster_19c720*);
void __cdecl FUN(Obj* obj, void* arg) {
    Caster_19c720 caster;
    void* p = Find(arg, &caster);
    obj->Set(p);
}