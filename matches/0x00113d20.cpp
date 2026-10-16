class Caster {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void Add(void*);
};
extern "C" void* __cdecl Find(void*, Caster*);
void FUN_00113d20(Owner* owner, void* track) {
    Caster caster;
    owner->Add(Find(track, &caster));
}