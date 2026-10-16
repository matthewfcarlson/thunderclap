class Caster {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void Set(void*);
};
void* Find(const char*, Caster*);
void Do(Owner* owner, const char* name) {
    Caster caster;
    void* p = Find(name, &caster);
    owner->Set(p);
}