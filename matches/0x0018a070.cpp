class Caster {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void Attach(void*);
};
extern "C" void* __cdecl Find(const char*, Caster*);
void Func(Owner* owner, const char* name) {
    Caster c;
    owner->Attach(Find(name, &c));
}