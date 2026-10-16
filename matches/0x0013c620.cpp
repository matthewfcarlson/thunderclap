class Caster {
  public:
    virtual void cast();
};
class Owner {
  public:
    void set(void*);
};
extern "C" void* find(void*, Caster*);
void target(Owner* owner, void* name) {
    Caster caster;
    owner->set(find(name, &caster));
}