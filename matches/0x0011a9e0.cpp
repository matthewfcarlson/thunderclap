class Caster {
  public:
    virtual void cast();
};
class Obj {
  public:
    void use(void*);
};
extern "C" void* find(void*, Caster*);
void target(Obj* o, void* name) {
    Caster caster;
    o->use(find(name, &caster));
}