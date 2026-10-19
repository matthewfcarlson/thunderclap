class Caster_17d8a0 {
  public:
    virtual void f();
};
void* __cdecl resolve(void*, Caster_17d8a0*);
class Obj {
  public:
    void use(void*);
};
void work(Obj* obj, void* id) {
    Caster_17d8a0 caster;
    void* p = resolve(id, &caster);
    obj->use(p);
}