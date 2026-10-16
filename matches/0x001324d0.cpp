class Caster {
  public:
    virtual void Cast();
};
extern void* __cdecl Find(const char*, Caster*);
class Owner {
  public:
    void Set(void*);
};
void Func(Owner* owner, const char* name) {
    Caster caster;
    void* p = Find(name, &caster);
    owner->Set(p);
}