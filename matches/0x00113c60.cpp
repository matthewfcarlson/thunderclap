class Caster {
  public:
    virtual void cast();
};
class Owner {
  public:
    void use(void*);
};
void* find(void*, Caster*);
extern "C" void FUN_00113c60(Owner* owner, void* value) {
    Caster caster;
    void* p = find(value, &caster);
    owner->use(p);
}