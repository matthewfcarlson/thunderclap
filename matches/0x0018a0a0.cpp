class Caster_18a0a0 {
  public:
    virtual void* Cast(void*);
};
class Owner {
  public:
    void* Add(void*);
};
extern "C" void* __cdecl Find(const char*, Caster_18a0a0*);
void* __cdecl Func(Owner* owner, const char* name) {
    Caster_18a0a0 c;
    return owner->Add(Find(name, &c));
}