class Caster_1139f0 {
  public:
    virtual void cast();
};
class Obj {
  public:
    void apply(void*);
};
extern void* lookup(const char*, Caster_1139f0*);
void FUN_001139f0(Obj* obj, const char* name) {
    Caster_1139f0 caster;
    void* p = lookup(name, &caster);
    obj->apply(p);
}