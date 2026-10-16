class Caster {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void Set(void*);
};
extern "C" void* Find(const char*, Caster*);
void FUN_00122c00(Owner* owner, const char* name) {
    Caster caster;
    owner->Set(Find(name, &caster));
}