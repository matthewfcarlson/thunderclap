class Caster {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Apply(void*);
};
extern void* Find(void*, Caster*);
void Func(Obj* obj, void* p) {
    Caster c;
    obj->Apply(Find(p, &c));
}