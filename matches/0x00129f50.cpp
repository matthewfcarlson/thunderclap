class Caster {
  public:
    virtual void Cast();
};
class Object {
  public:
    void Use(void*);
};
extern "C" void* Find(void*, Caster*);
void Target(Object* obj, void* name) {
    Caster caster;
    obj->Use(Find(name, &caster));
}
