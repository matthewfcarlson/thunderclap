class Caster {
  public:
    virtual void cast();
};
extern "C" void* Find(const char*, Caster*);
class Owner {
  public:
    void Apply(void*);
};
void Func(Owner* owner, const char* name) {
    Caster caster;
    void* p = Find(name, &caster);
    owner->Apply(p);
}