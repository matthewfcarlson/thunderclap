class Caster {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Set(void*);
};
extern void* Find(const char*, Caster*);
void FUN_00146370(Obj* obj, const char* name) {
    Caster caster;
    obj->Set(Find(name, &caster));
}