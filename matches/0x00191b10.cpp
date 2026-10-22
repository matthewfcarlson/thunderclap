class TrackFactoryCasterTemplate_191b10 {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void Set(void*);
};
void* Find(const char*, TrackFactoryCasterTemplate_191b10*);
void Do(Owner* owner, const char* name) {
    TrackFactoryCasterTemplate_191b10 caster;
    void* p = Find(name, &caster);
    owner->Set(p);
}