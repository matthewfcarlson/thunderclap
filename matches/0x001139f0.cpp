class Caster {
  public:
    virtual void cast();
};
class Obj {
  public:
    void apply(void*);
};
extern void* lookup(const char*, Caster*);
void FUN_001139f0(Obj* obj, const char* name) {
    Caster caster;
    void* p = lookup(name, &caster);
    obj->apply(p);
}