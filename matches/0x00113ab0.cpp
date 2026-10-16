class Caster {
  public:
    virtual void cast();
};
class Obj {
  public:
    int Get(void*);
};
extern "C" void* Find(const char*, Caster*);
int Func(Obj* obj, const char* name) {
    Caster caster;
    return obj->Get(Find(name, &caster));
}