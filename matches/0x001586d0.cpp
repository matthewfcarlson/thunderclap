class Caster {
  public:
    virtual void cast();
};
class Owner {
  public:
    void set(void*);
};
void* lookup(void*, Caster*);
void fn(Owner* owner, void* name) {
    Caster caster;
    void* x = lookup(name, &caster);
    owner->set(x);
}