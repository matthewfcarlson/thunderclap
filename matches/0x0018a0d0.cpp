class TrackFactoryCasterTemplate_18a0d0 {
  public:
    virtual void cast();
};
class Track {
  public:
    void apply(void*);
};
extern "C" void* find(void*, TrackFactoryCasterTemplate_18a0d0*);
void target(Track* track, void* name) {
    TrackFactoryCasterTemplate_18a0d0 caster;
    track->apply(find(name, &caster));
}