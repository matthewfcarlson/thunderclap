class Caster {
  public:
    virtual void Cast();
};
extern Caster* __cdecl Lookup(void*, Caster*);
class Obj {
  public:
    void* Get(Caster*);
};
void* fn(Obj* o, void* p) {
    Caster c;
    return o->Get(Lookup(p, &c));
}