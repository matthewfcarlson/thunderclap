class TrackFactoryCasterTemplate_18b2e0 {
  public:
    virtual void Cast();
};
extern "C" void* __cdecl Find(void*, TrackFactoryCasterTemplate_18b2e0*);
class Target {
  public:
    void* Set(void*);
};
void* __cdecl FUN_0018b2e0(Target* target, void* arg) {
    TrackFactoryCasterTemplate_18b2e0 caster;
    void* p = Find(arg, &caster);
    return target->Set(p);
}