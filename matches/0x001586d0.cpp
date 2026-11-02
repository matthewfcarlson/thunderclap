class TrackFactoryCasterTemplate_1586d0 {
  public:
    virtual void cast();
};
class Owner {
  public:
    void set(void*);
};
void* lookup(void*, TrackFactoryCasterTemplate_1586d0*);
extern "C" void FUN_001586d0(Owner* owner, void* name) {
    TrackFactoryCasterTemplate_1586d0 caster;
    void* x = lookup(name, &caster);
    owner->set(x);
}