class Caster_2391d0 {
  public:
    virtual void Cast();
};
class Obj {
  public:
    void Set(void*);
};
extern "C" void* Find(const char*, Caster_2391d0*);
void Func(Obj* obj, const char* name) {
    Caster_2391d0 caster;
    obj->Set(Find(name, &caster));
}