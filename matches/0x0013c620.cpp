class Caster_13c620 {
  public:
    virtual void cast();
};
class Owner {
  public:
    void set(void*);
};
extern "C" void* find(void*, Caster_13c620*);
void target(Owner* owner, void* name) {
    Caster_13c620 caster;
    owner->set(find(name, &caster));
}