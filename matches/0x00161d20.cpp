class TrackFactoryCasterTemplate_161d20 {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void Apply(void*);
};
void* __cdecl Find(void*, TrackFactoryCasterTemplate_161d20*);
void __cdecl FUN_00161d20(Owner* owner, void* source) {
    TrackFactoryCasterTemplate_161d20 caster;
    owner->Apply(Find(source, &caster));
}