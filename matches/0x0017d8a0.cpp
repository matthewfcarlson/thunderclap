class Caster_17d8a0 {
  public:
    virtual void f();
};
void* __cdecl resolve(void*, Caster_17d8a0*);
class Obj {
  public:
    void use(void*);
};
extern "C" void FUN_0017d8a0(Obj* obj, void* id) {
    Caster_17d8a0 caster;
    void* p = resolve(id, &caster);
    obj->use(p);
}