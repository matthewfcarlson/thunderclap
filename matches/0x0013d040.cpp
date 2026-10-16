class Caster {
  public:
    virtual void cast();
};
class Owner {
  public:
    void apply(void*);
};
extern "C" void* lookup(void*, Caster*);
void fn(Owner* owner, void* name) {
    Caster c;
    owner->apply(lookup(name, &c));
}