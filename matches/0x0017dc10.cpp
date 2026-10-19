class Caster_17dc10 {
  public:
    virtual void Cast();
};
class Target {
  public:
    void Set(void*);
};
void* Find(void*, Caster_17dc10*);
void FUN_0017dc10(Target* obj, void* name) {
    Caster_17dc10 caster;
    obj->Set(Find(name, &caster));
}