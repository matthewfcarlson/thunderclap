class Caster {
  public:
    virtual void cast();
};
class Obj {
  public:
    void use(void*);
};
extern "C" void* lookup(void*, Caster*);
void target(Obj* a, void* b) {
    Caster caster;
    a->use(lookup(b, &caster));
}