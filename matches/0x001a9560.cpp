class Caster_1a9560 {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void Apply(void*);
};
extern "C" void* __cdecl Find(void*, Caster_1a9560*);
void Fn(Owner* owner, void* value) {
    Caster_1a9560 caster;
    void* result = Find(value, &caster);
    owner->Apply(result);
}