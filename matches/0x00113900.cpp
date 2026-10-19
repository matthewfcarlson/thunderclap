class Caster_113900 {
  public:
    virtual void cast();
};
class Obj {
  public:
    void apply(void*);
};
extern "C" void* find(const char*, Caster_113900*);
void target(Obj* obj, const char* name) {
    Caster_113900 caster;
    void* p = find(name, &caster);
    obj->apply(p);
}