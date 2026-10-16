class Caster {
  public:
    virtual void cast();
};
class Recipient {
  public:
    void use(void*);
};
extern void* lookup(void*, Caster*);
void func(Recipient* r, void* name) {
    Caster caster;
    void* p = lookup(name, &caster);
    r->use(p);
}