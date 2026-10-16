class Caster {
  public:
    virtual void Cast();
};
extern "C" void* find(void*, Caster*);
class Obj {
  public:
    void set(void*);
};
void func(Obj* obj, void* value) {
    Caster caster;
    void* p = find(value, &caster);
    obj->set(p);
}