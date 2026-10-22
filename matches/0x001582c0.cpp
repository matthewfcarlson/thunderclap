class TrackFactoryCasterTemplate_1582c0 {
  public:
    virtual void cast();
};
class Track {
  public:
    void apply(void*);
};
extern "C" void* find(void*, TrackFactoryCasterTemplate_1582c0*);
void fun(Track* t, void* name) {
    TrackFactoryCasterTemplate_1582c0 caster;
    t->apply(find(name, &caster));
}