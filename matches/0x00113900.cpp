class Caster {
  public:
    virtual void cast();
};
class Obj {
  public:
    void apply(void*);
};
extern "C" void* find(const char*, Caster*);
void target(Obj* obj, const char* name) {
    Caster caster;
    void* p = find(name, &caster);
    obj->apply(p);
}