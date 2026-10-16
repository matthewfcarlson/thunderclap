class Caster {
  public:
    virtual void Cast();
};
class Target {
  public:
    void Set(void*);
};
void* Find(void*, Caster*);
void FUN_0017dc10(Target* obj, void* name) {
    Caster caster;
    obj->Set(Find(name, &caster));
}