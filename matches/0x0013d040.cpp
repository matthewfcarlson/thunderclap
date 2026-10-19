class Caster_13d040 {
  public:
    virtual void cast();
};
class Owner {
  public:
    void apply(void*);
};
extern "C" void* lookup(void*, Caster_13d040*);
void fn(Owner* owner, void* name) {
    Caster_13d040 c;
    owner->apply(lookup(name, &c));
}