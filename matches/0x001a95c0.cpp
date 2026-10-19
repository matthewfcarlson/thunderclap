class Caster_1a95c0 {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Do(void*);
};
void* __cdecl Find(void*, Caster_1a95c0*);
void __cdecl Target(Obj* obj, void* p) {
    Caster_1a95c0 caster;
    obj->Do(Find(p, &caster));
}