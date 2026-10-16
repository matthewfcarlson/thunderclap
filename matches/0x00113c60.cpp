class Caster {
  public:
    virtual void cast();
};
class Owner {
  public:
    void use(void*);
};
void* find(void*, Caster*);
void target(Owner* owner, void* value) {
    Caster caster;
    void* p = find(value, &caster);
    owner->use(p);
}