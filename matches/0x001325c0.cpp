class TrackFactoryCasterTemplate_1325c0 {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void Set(void*);
};
extern "C" void* Find(const char*, TrackFactoryCasterTemplate_1325c0*);
void Func(Owner* owner, const char* name) {
    TrackFactoryCasterTemplate_1325c0 caster;
    void* p = Find(name, &caster);
    owner->Set(p);
}