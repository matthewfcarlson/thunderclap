class Caster {
  public:
    virtual void Fn();
};
class Obj {
  public:
    void Do(void*);
};
void* Find(void*, Caster*);
void Target(Obj* obj, void* key) {
    Caster caster;
    obj->Do(Find(key, &caster));
}