class Caster {
  public:
    virtual void Cast();
};
class TrackFactoryCaster : public Caster {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Use(void*);
};
void* __cdecl Find(void*, Caster*);
void __cdecl Target(Obj* obj, void* key) {
    TrackFactoryCaster caster;
    obj->Use(Find(key, &caster));
}