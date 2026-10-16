class Caster {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Apply(int);
};
extern int __cdecl Find(int, Caster*);
void Work(Obj* obj, int id) {
    Caster caster;
    obj->Apply(Find(id, &caster));
}