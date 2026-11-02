class TrackFactoryCasterTemplate_1a1d20 {
  public:
    virtual void cast();
};
class Track {
  public:
    void* get(void*);
};
extern "C" void* FUN_00236ac0(const char*, TrackFactoryCasterTemplate_1a1d20*);
extern "C" void* FUN_001a1d20(Track* t, const char* name) {
    TrackFactoryCasterTemplate_1a1d20 c;
    return t->get(FUN_00236ac0(name, &c));
}