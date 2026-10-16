class Caster {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void Set(void*);
};
void* Find(const char*, Caster*);
void FUN_0019d130(Owner* owner, const char* name) {
    Caster caster;
    owner->Set(Find(name, &caster));
}