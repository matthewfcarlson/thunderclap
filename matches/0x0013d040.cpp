class TrackFactoryCasterTemplate_13d040 {
  public:
    virtual void cast();
};
class Owner {
  public:
    void apply(void*);
};
extern "C" void* lookup(void*, TrackFactoryCasterTemplate_13d040*);
void fn(Owner* owner, void* name) {
    TrackFactoryCasterTemplate_13d040 c;
    owner->apply(lookup(name, &c));
}