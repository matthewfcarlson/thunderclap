class Caster {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Set(void*);
};
void* Find(int, Caster*);
void Target(Obj* obj, int id) {
    Caster caster;
    obj->Set(Find(id, &caster));
}