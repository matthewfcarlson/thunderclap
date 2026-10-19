class Caster_1a94a0 {
  public:
    virtual void Cast();
};
extern "C" void* find(void*, Caster_1a94a0*);
class Obj {
  public:
    void set(void*);
};
void func(Obj* obj, void* value) {
    Caster_1a94a0 caster;
    void* p = find(value, &caster);
    obj->set(p);
}