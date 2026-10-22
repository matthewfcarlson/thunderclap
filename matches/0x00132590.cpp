class TrackFactoryCasterTemplate_132590 {
  public:
    virtual void f();
};
extern "C" void* __cdecl Find(char*, TrackFactoryCasterTemplate_132590*);
class Owner {
  public:
    void Add(void*);
};
void __cdecl target(Owner* owner, char* name) {
    TrackFactoryCasterTemplate_132590 caster;
    owner->Add(Find(name, &caster));
}