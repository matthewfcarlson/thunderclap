class Caster {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Set(void*);
};
extern void* Find(void*, Caster*);
void target(Obj* o, void* name) {
    Caster c;
    void* p = Find(name, &c);
    o->Set(p);
}