class Caster_17d580 {
  public:
    virtual void Cast();
};
extern "C" void* __cdecl Find(void*, Caster_17d580*);
class Obj {
  public:
    void Take(void*);
};
extern "C" void __cdecl FUN_0017d580(Obj* obj, void* value) {
    Caster_17d580 caster;
    obj->Take(Find(value, &caster));
}