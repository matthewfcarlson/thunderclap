class Caster_18a070 {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void Attach(void*);
};
extern "C" void* __cdecl Find(const char*, Caster_18a070*);
void Func(Owner* owner, const char* name) {
    Caster_18a070 c;
    owner->Attach(Find(name, &c));
}