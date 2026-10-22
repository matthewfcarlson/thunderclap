class TrackFactoryCasterTemplate_13c620 {
  public:
    virtual void cast();
};
class Owner {
  public:
    void set(void*);
};
extern "C" void* find(void*, TrackFactoryCasterTemplate_13c620*);
void target(Owner* owner, void* name) {
    TrackFactoryCasterTemplate_13c620 caster;
    owner->set(find(name, &caster));
}