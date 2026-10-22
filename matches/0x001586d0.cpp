class TrackFactoryCasterTemplate_1586d0 {
  public:
    virtual void cast();
};
class Owner {
  public:
    void set(void*);
};
void* lookup(void*, TrackFactoryCasterTemplate_1586d0*);
void fn(Owner* owner, void* name) {
    TrackFactoryCasterTemplate_1586d0 caster;
    void* x = lookup(name, &caster);
    owner->set(x);
}