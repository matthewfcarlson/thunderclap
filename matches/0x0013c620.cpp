class TrackFactoryCasterTemplate_13c620 {
  public:
    virtual void cast();
};
class Owner {
  public:
    void set(void*);
};
extern "C" void* find(void*, TrackFactoryCasterTemplate_13c620*);
extern "C" void FUN_0013c620(Owner* owner, void* name) {
    TrackFactoryCasterTemplate_13c620 caster;
    owner->set(find(name, &caster));
}