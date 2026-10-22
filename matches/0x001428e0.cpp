class TrackFactoryCasterTemplate_1428e0 {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void Add(void*);
};
extern "C" void* __cdecl Find(void*, TrackFactoryCasterTemplate_1428e0*);
void Func(Owner* owner, void* name) {
    TrackFactoryCasterTemplate_1428e0 caster;
    owner->Add(Find(name, &caster));
}