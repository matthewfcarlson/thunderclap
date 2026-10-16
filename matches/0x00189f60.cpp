class Caster {
  public:
    virtual void cast();
};
class Obj {
  public:
    int Do(void*);
};
extern void* Find(int, Caster*);
int Func(Obj* obj, int name) {
    Caster c;
    return obj->Do(Find(name, &c));
}