class TrackFactoryCasterTemplate_139360 {
  public:
    virtual void Dummy();
};
class Owner {
  public:
    void Set(void*);
};
void* __cdecl Find(const char*, TrackFactoryCasterTemplate_139360*);
extern "C" void FUN_00139360(Owner* owner, const char* name) {
    TrackFactoryCasterTemplate_139360 caster;
    owner->Set(Find(name, &caster));
}