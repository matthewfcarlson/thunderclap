class Caster {
  public:
    virtual void Dummy();
};
class Owner {
  public:
    void Set(void*);
};
void* __cdecl Find(const char*, Caster*);
void Target(Owner* owner, const char* name) {
    Caster caster;
    owner->Set(Find(name, &caster));
}