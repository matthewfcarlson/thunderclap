class Caster {
  public:
    virtual void Check();
};
class Obj {
  public:
    void Apply(void*);
};
extern "C" void* Find(void*, Caster*);
void Target(Obj* obj, void* name) {
    Caster c;
    obj->Apply(Find(name, &c));
}