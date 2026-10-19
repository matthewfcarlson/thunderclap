class Caster_162820 {
  public:
    virtual void f();
};
class Obj {
  public:
    void use(void*);
};
void* Find(void*, Caster_162820*);
void target(Obj* o, void* p) {
    Caster_162820 c;
    o->use(Find(p, &c));
}