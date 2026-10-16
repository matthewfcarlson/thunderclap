class Caster {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Set(void*);
};
extern "C" void* Find(const char*, Caster*);
void Func(Obj* obj, const char* name) {
    Caster caster;
    obj->Set(Find(name, &caster));
}