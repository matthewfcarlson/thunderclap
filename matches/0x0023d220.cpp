class Caster {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Apply(void*);
};
extern "C" void* Get(void*, Caster*);
void Func(Obj* obj, void* x) {
    Caster caster;
    void* p = Get(x, &caster);
    obj->Apply(p);
}