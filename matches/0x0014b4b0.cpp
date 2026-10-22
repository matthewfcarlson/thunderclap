class TrackFactoryCasterTemplate_14b4b0 {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void Set(void*);
};
extern "C" void* __cdecl Find(const char*, TrackFactoryCasterTemplate_14b4b0*);
void Func(Owner* owner, const char* name) {
    TrackFactoryCasterTemplate_14b4b0 caster;
    void* p = Find(name, &caster);
    owner->Set(p);
}