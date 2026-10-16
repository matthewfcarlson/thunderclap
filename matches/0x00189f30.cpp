class Caster {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Apply(void*);
};
extern "C" void* Find(void*, Caster*);
void fun(Obj* o, void* p) {
    Caster c;
    o->Apply(Find(p, &c));
}