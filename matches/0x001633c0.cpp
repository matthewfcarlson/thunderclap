class Caster {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Do(void*);
};
extern void* Find(void*, Caster*);
void Target(Obj* obj, void* value) {
    Caster c;
    void* p = Find(value, &c);
    obj->Do(p);
}