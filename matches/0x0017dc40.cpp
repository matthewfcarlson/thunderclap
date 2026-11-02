class Caster_17dc40 {
  public:
    virtual void Cast();
};
class Target {
  public:
    void Set(void*);
};
extern void* Find(void*, Caster_17dc40*);
extern "C" void FUN_0017dc40(Target* target, void* name) {
    Caster_17dc40 caster;
    target->Set(Find(name, &caster));
}