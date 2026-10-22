class TrackFactoryCasterTemplate_19d130 {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void Set(void*);
};
void* Find(const char*, TrackFactoryCasterTemplate_19d130*);
void FUN_0019d130(Owner* owner, const char* name) {
    TrackFactoryCasterTemplate_19d130 caster;
    owner->Set(Find(name, &caster));
}