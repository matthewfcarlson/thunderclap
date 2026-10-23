class TrackFactoryCasterTemplate_1582c0 {
  public:
    virtual void cast();
};
class Track {
  public:
    void apply(void*);
};
extern "C" void* FUN_00236ac0(void*, TrackFactoryCasterTemplate_1582c0*);
void fun(Track* t, void* name) {
    TrackFactoryCasterTemplate_1582c0 caster;
    t->apply(FUN_00236ac0(name, &caster));
}