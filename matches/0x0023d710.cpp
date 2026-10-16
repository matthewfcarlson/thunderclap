class Caster {
  public:
    virtual void Dummy();
};
class Owner {
  public:
    void Set(void*);
};
extern void* Cast(void*, Caster*);
void Func(Owner* owner, void* ptr) {
    Caster caster;
    owner->Set(Cast(ptr, &caster));
}