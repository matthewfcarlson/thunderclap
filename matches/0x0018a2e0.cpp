class Caster_18a2e0 {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Apply(void*);
};
extern void* Find(void*, Caster_18a2e0*);
void Func(Obj* obj, void* p) {
    Caster_18a2e0 c;
    obj->Apply(Find(p, &c));
}