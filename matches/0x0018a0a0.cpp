class Caster {
  public:
    virtual void* Cast(void*);
};
class Owner {
  public:
    void* Add(void*);
};
extern "C" void* __cdecl Find(const char*, Caster*);
void* __cdecl Func(Owner* owner, const char* name) {
    Caster c;
    return owner->Add(Find(name, &c));
}