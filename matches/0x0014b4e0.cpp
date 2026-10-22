class TrackFactoryCasterTemplate_14b4e0 {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void Add(void*);
};
void* Find(const char*, TrackFactoryCasterTemplate_14b4e0*);
void Target(Owner* owner, const char* name) {
    TrackFactoryCasterTemplate_14b4e0 caster;
    void* p = Find(name, &caster);
    owner->Add(p);
}