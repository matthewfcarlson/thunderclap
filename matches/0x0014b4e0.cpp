class Caster {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void Add(void*);
};
void* Find(const char*, Caster*);
void Target(Owner* owner, const char* name) {
    Caster caster;
    void* p = Find(name, &caster);
    owner->Add(p);
}