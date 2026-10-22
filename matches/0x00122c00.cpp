class TrackFactoryCasterTemplate_122c00 {
  public:
    virtual void Cast();
};
class Owner {
  public:
    void Set(void*);
};
extern "C" void* Find(const char*, TrackFactoryCasterTemplate_122c00*);
void FUN_00122c00(Owner* owner, const char* name) {
    TrackFactoryCasterTemplate_122c00 caster;
    owner->Set(Find(name, &caster));
}