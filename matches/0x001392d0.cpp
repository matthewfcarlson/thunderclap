class Caster_1392d0 {
  public:
    virtual void cast();
};
class Recipient {
  public:
    void use(void*);
};
extern void* lookup(void*, Caster_1392d0*);
void func(Recipient* r, void* name) {
    Caster_1392d0 caster;
    void* p = lookup(name, &caster);
    r->use(p);
}