class Caster {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Set(void*);
};
void* Find(int, Caster*);
extern "C" void FUN_00113a80(Obj* obj, int id) {
    Caster caster;
    obj->Set(Find(id, &caster));
}