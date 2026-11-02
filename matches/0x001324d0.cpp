class TrackFactoryCasterTemplate_1324d0 {
  public:
    virtual void Cast();
};
extern void* __cdecl Find(const char*, TrackFactoryCasterTemplate_1324d0*);
class Owner {
  public:
    void Set(void*);
};
extern "C" void FUN_001324d0(Owner* owner, const char* name) {
    TrackFactoryCasterTemplate_1324d0 caster;
    void* p = Find(name, &caster);
    owner->Set(p);
}