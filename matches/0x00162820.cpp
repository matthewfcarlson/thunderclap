class Caster {
  public:
    virtual void f();
};
class Obj {
  public:
    void use(void*);
};
void* Find(void*, Caster*);
void target(Obj* o, void* p) {
    Caster c;
    o->use(Find(p, &c));
}