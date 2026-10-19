class Caster_23d710 {
  public:
    virtual void Dummy();
};
class Owner {
  public:
    void Set(void*);
};
extern void* Cast(void*, Caster_23d710*);
void Func(Owner* owner, void* ptr) {
    Caster_23d710 caster;
    owner->Set(Cast(ptr, &caster));
}