class Caster {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void Set(void*);
};
extern void* Find(const char*, Caster*);
void Func(Owner* o, const char* name) {
    Caster caster;
    o->Set(Find(name, &caster));
}