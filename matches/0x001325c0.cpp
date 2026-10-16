class Caster {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void Set(void*);
};
extern "C" void* Find(const char*, Caster*);
void Func(Owner* owner, const char* name) {
    Caster caster;
    void* p = Find(name, &caster);
    owner->Set(p);
}